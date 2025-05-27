// Kernel definition
__global__ void MatAdd(float A[N][N], float B[N][N],
    float C[N][N])
    {
        int i = blockIdx.x * blockDim.x + threadIdx.x;
        int j = blockIdx.y * blockDim.y + threadIdx.y;
        if (i < N && j < N)
            C[i][j] = A[i][j] + B[i][j];
    }
    
    int main()
    {
        ...
        // Kernel invocation
        dim3 threadsPerBlock(16, 16);
        dim3 numBlocks(N / threadsPerBlock.x, N / threadsPerBlock.y);
        MatAdd<<<numBlocks, threadsPerBlock>>>(A, B, C);
        ...
    }

///////////////
cudaLaunchKernelEx
__cluster_dims__(X,Y,Z)

// Kernel definition
// Compile time cluster size 2 in X-dimension and 1 in Y and Z dimension
__global__ void __cluster_dims__(2, 1, 1) cluster_kernel(float *input, float* output)
{

}

int main()
{
    float *input, *output;
    // Kernel invocation with compile time cluster size
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks(N / threadsPerBlock.x, N / threadsPerBlock.y);

    // The grid dimension is not affected by cluster launch, and is still enumerated
    // using number of blocks.
    // The grid dimension must be a multiple of cluster size.
    cluster_kernel<<<numBlocks, threadsPerBlock>>>(input, output);
}

////////////////////////////////////////////////////////////////////////////
cudaLaunchKernelEx
////////////////////////////////////////////////////////////////////////////
//Using cudaLaunchKernelEx
// Kernel definition
// No compile time attribute attached to the kernel
__global__ void cluster_kernel(float *input, float* output)
{

}

int main()
{
    float *input, *output;
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks(N / threadsPerBlock.x, N / threadsPerBlock.y);

    // Kernel invocation with runtime cluster size
    {
        cudaLaunchConfig_t config = {0};
        // The grid dimension is not affected by cluster launch, and is still enumerated
        // using number of blocks.
        // The grid dimension should be a multiple of cluster size.
        config.gridDim = numBlocks;
        config.blockDim = threadsPerBlock;

        cudaLaunchAttribute attribute[1];
        attribute[0].id = cudaLaunchAttributeClusterDimension;
        attribute[0].val.clusterDim.x = 2; // Cluster size in X-dimension
        attribute[0].val.clusterDim.y = 1;
        attribute[0].val.clusterDim.z = 1;
        config.attrs = attribute;
        config.numAttrs = 1;

        cudaLaunchKernelEx(&config, cluster_kernel, input, output);
    }
}


////////////////////////////////////////////////////////////////
UNIFIED MEMORY MODEL
///////////////////////////////////////////////////////////////

__host__ cudaError_t cudaMallocManaged(void **devPtr, size_t size);
        //>> device code is not able to call cudaMallocManaged


__global__ void printme(char *str) {
    printf(str);
  }
  
  int main() {
    // Allocate 100 bytes of memory, accessible to both Host and Device code
    char *s;
    cudaMallocManaged(&s, 100);
    // Note direct Host-code use of "s"
    strncpy(s, "Hello Unified Memory\n", 99);
    // Here we pass "s" to a kernel without explicitly copying
    printme<<< 1, 1 >>>(s);
    cudaDeviceSynchronize();
    // Free as for normal CUDA allocations
    cudaFree(s); 
    return  0;
  }


////////////////////////////////
__managed__ int value;


__global__ void write_value(int* ptr, int v) {
    *ptr = v;
  }
  
  // Requires CUDA Managed Memory support
  __managed__ int value;
  
  int main() {
    write_value<<<1, 1>>>(&value, 1);
    // Synchronize required
    // (before, cudaMemcpy was synchronizing)
    cudaDeviceSynchronize();
    printf("value = %d\n", value);
    return 0;
  }

//////////////////////////////////
//where memory was allocated

char const* kind(cudaPointerAttributes a, bool pma, bool cma) {
    switch(a.type) {
    case cudaMemoryTypeHost: return pma?
      "Unified: CUDA Host or Registered Memory" :
      "Not Unified: CUDA Host or Registered Memory";
    case cudaMemoryTypeDevice: return "Not Unified: CUDA Device Memory";
    case cudaMemoryTypeManaged: return cma?
      "Unified: CUDA Managed Memory" : "Not Unified: CUDA Managed Memory";
    case cudaMemoryTypeUnregistered: return pma?
      "Unified: System-Allocated Memory" :
      "Not Unified: System-Allocated Memory";
    default: return "unknown";
    }
}

void check_pointer(int i, void* ptr) {
  cudaPointerAttributes attr;
  cudaPointerGetAttributes(&attr, ptr);
  int pma = 0, cma = 0, device = 0;
  cudaGetDevice(&device);
  cudaDeviceGetAttribute(&pma, cudaDevAttrPageableMemoryAccess, device);
  cudaDeviceGetAttribute(&cma, cudaDevAttrConcurrentManagedAccess, device);
  printf("Pointer %d: memory is %s\n", i, kind(attr, pma, cma));
}

__managed__ int managed_var = 5;

int main() {
  int* ptr[5];
  ptr[0] = (int*)malloc(sizeof(int));
  cudaMallocManaged(&ptr[1], sizeof(int));
  cudaMallocHost(&ptr[2], sizeof(int));
  cudaMalloc(&ptr[3], sizeof(int));
  ptr[4] = &managed_var;

  for (int i = 0; i < 5; ++i) check_pointer(i, ptr[i]);
  
  cudaFree(ptr[3]);
  cudaFreeHost(ptr[2]);
  cudaFree(ptr[1]);
  free(ptr[0]);
  return 0;
}

///////////////////////
PErFOMANCE HINTS

cudaError_t cudaMemPrefetchAsync(const void *devPtr,
    size_t count,
    int dstDevice,
    cudaStream_t stream);

    void test_prefetch_managed(cudaStream_t s) {
        char *data;
        cudaMallocManaged(&data, N);
        init_data(data, N);                                     // execute on CPU
        cudaMemPrefetchAsync(data, N, myGpuId, s);              // prefetch to GPU
        mykernel<<<(N + TPB - 1) / TPB, TPB, 0, s>>>(data, N);  // execute on GPU
        cudaMemPrefetchAsync(data, N, cudaCpuDeviceId, s);      // prefetch to CPU
        cudaStreamSynchronize(s);
        use_data(data, N);
        cudaFree(data);
      }

////
Data Usage

cudaError_t cudaMemAdvise(const void *devPtr,
    size_t count,
    enum cudaMemoryAdvise advice,
    int device);


    void test_advise_managed(cudaStream_t stream) {
        char *dataPtr;
        size_t dataSize = 64 * TPB;  // 16 KiB
        // Allocate memory using cudaMallocManaged
        // (malloc may be used on systems with full CUDA Unified memory support)
        cudaMallocManaged(&dataPtr, dataSize);
        // Set the advice on the memory region
        cudaMemAdvise(dataPtr, dataSize, cudaMemAdviseSetReadMostly, myGpuId);
        int outerLoopIter = 0;
        while (outerLoopIter < maxOuterLoopIter) {
          // The data is written to in the outer loop on the CPU
          init_data(dataPtr, dataSize);
          // The data is made available to all GPUs by prefetching.
          // Prefetching here causes read duplication of data instead
          // of data migration
          for (int device = 0; device < maxDevices; device++) {
            cudaMemPrefetchAsync(dataPtr, dataSize, device, stream);
          }
          // The kernel only reads this data in the inner loop
          int innerLoopIter = 0;
          while (innerLoopIter < maxInnerLoopIter) {
            mykernel<<<32, TPB, 0, stream>>>((const char *)dataPtr, dataSize);
            innerLoopIter++;
          }
          outerLoopIter++;
        }
        cudaFree(dataPtr);
      }


////////////////
//query data usage attributes on managed memory
cudaMemRangeGetAttribute(void *data,
    size_t dataSize,
    enum cudaMemRangeAttribute attribute,
    const void *devPtr,
    size_t count);

/////////////////////////
EXAMPLES
__global__ void kernel(const char* type, const char* data) {
    static const int n_char = 8;
    printf("%s - first %d characters: '", type, n_char);
    for (int i = 0; i < n_char; ++i) printf("%c", data[i]);
    printf("'\n");
  }

//malloc and then call the kernel
void test_malloc() {
    const char test_string[] = "Hello World";
    char* heap_data = (char*)malloc(sizeof(test_string));
    strncpy(heap_data, test_string, sizeof(test_string));
    kernel<<<1, 1>>>("malloc", heap_data);
    ASSERT(cudaDeviceSynchronize() == cudaSuccess,
      "CUDA failed with '%s'", cudaGetErrorString(cudaGetLastError()));
    free(heap_data);
  }


//cudaMallocManaged
  void test_managed() {
    const char test_string[] = "Hello World";
    char* data;
    cudaMallocManaged(&data, sizeof(test_string));
    strncpy(data, test_string, sizeof(test_string));
    kernel<<<1, 1>>>("managed", data);
    ASSERT(cudaDeviceSynchronize() == cudaSuccess,
      "CUDA failed with '%s'", cudaGetErrorString(cudaGetLastError()));
    cudaFree(data);
  }



  void test_stack() {
    const char test_string[] = "Hello World";
    kernel<<<1, 1>>>("stack", test_string);
    ASSERT(cudaDeviceSynchronize() == cudaSuccess,
      "CUDA failed with '%s'", cudaGetErrorString(cudaGetLastError()));
  }



  void test_static() {
    static const char test_string[] = "Hello World";
    kernel<<<1, 1>>>("static", test_string);
    ASSERT(cudaDeviceSynchronize() == cudaSuccess,
      "CUDA failed with '%s'", cudaGetErrorString(cudaGetLastError()));
  }


  const char global_string[] = "Hello World";

void test_global() {
  kernel<<<1, 1>>>("global", global_string);
  ASSERT(cudaDeviceSynchronize() == cudaSuccess,
    "CUDA failed with '%s'", cudaGetErrorString(cudaGetLastError()));
}


// declared in separate file, see below
extern char* ext_data;

void test_extern() {
  kernel<<<1, 1>>>("extern", ext_data);
  ASSERT(cudaDeviceSynchronize() == cudaSuccess,
    "CUDA failed with '%s'", cudaGetErrorString(cudaGetLastError()));
}



////////////////////////
//File backed memory

__global__ void kernel(const char* type, const char* data) {
    static const int n_char = 8;
    printf("%s - first %d characters: '", type, n_char);
    for (int i = 0; i < n_char; ++i) printf("%c", data[i]);
    printf("'\n");
  }


  vo
  
  () {
    int fd = open(INPUT_FILE_NAME, O_RDONLY);
    ASSERT(fd >= 0, "Invalid file handle");
    struct stat file_stat;
    int status = fstat(fd, &file_stat);
    ASSERT(status >= 0, "Invalid file stats");
    char* mapped = (char*)mmap(0, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    ASSERT(mapped != MAP_FAILED, "Cannot map file into memory");
    kernel<<<1, 1>>>("file-backed", mapped);
    ASSERT(cudaDeviceSynchronize() == cudaSuccess,
      "CUDA failed with '%s'", cudaGetErrorString(cudaGetLastError()));
    ASSERT(munmap(mapped, file_stat.st_size) == 0, "Cannot unmap file");
    ASSERT(close(fd) == 0, "Cannot close file");
  }




