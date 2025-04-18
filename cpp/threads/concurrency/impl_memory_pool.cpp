

class MemoryPool {
public:
    MemoryPool(size_t blockSize, size_t numBlocks);
    ~MemoryPool();

    void* allocate();
    void deallocate(void* ptr);

private:
    char* pool_; // Pre-allocated memory
    size_t blockSize_;
    size_t numBlocks_;
    char* freeList_; // Linked list of free blocks
};

MemoryPool::MemoryPool(size_t blockSize, size_t numBlocks) : blockSize_(blockSize), numBlocks_(numBlocks) {
    pool_ = new char[blockSize_ * numBlocks_];
    freeList_ = pool_;

    // Initialize free list
    for (size_t i = 0; i < numBlocks_ - 1; ++i) {
        *(char**)(pool_ + i * blockSize_) = pool_ + (i + 1) * blockSize_;
    }
    *(char**)(pool_ + (numBlocks_ - 1) * blockSize_) = nullptr;
}

MemoryPool::~MemoryPool() {
    delete[] pool_;
}

void* MemoryPool::allocate() {
    if (freeList_ == nullptr) {
        return nullptr; // Pool is empty
    }

    void* block = freeList_;
    freeList_ = *(char**)freeList_;
    return block;
}

void MemoryPool::deallocate(void* ptr) {
    *(char**)ptr = freeList_;
    freeList_ = (char*)ptr;
}