/*
seg faults are caused when the program tries to access the memory not allocated to it.

gdb
address sanitizer

*/
#include<iostream>

//modifying string literals
void failure_tests_string_literal() {
    //string literals are stored in the read-only section of memory.
    char* str = "gfg";
    *(str + 1) = 'n';  //=> this line is a problem..
    std::cout << "end of failure_tests" << std::endl;
}


//accessing freed memory
void access_free_memory() {
    // allocating memory to p
    int* p = (int*)malloc(sizeof(int));

    *p = 100;

    // deallocated the space allocated to p
    free(p);
    p = nullptr

    //  segmentation fault
    //  as now this statement is illegal
    *p = 110;
    std::cout << "end of access_free_memory" << std::endl;
}


void arrays_out_of_bound_index() {
    int arr[2];

    // Accessing out of bound
    arr[3] = 10;
    std::cout << "end of arrays_out_of_bound_index" << std::endl;
}


void buffer_oveflow() {
    char ref[20] = "This is a long string";
    char buf[10];
    sscanf(ref, "%s", buf);
}


void stack_overflow() {
    int array[2000000000];
}

int main() {
    //failure_tests_string_literal();

    //access_free_memory();

    //arrays_out_of_bound_index();

    //stack_overflow();

    buffer_oveflow();

    return 0;
}