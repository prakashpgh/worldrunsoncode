#include <iostream>

/**
 * reference is a const pointer, with default indirection,
 
--------------------------------------------------------------------------------------
Use references whereever possible.
    1) safety.. no null values.. references cannot be null, pointers can be null
    2) no dereferencing required.

--------------------------------------------------------------------------------------
differences between pointer and reference
1) Nullability: pointer can be null, reference cannot be null, once a reference is bound to an object it remains bound to that object
2) Reassignment: pointer can be reassigned, reference cannot be
3) syntax
4) arithmetic
5) Level of indirection: pointer itself is an object, it holds the memory address
                        reference is not a separate object
6) sizeof() 



#include <iostream>

int main() {
    int x = 10;

    // Pointer
    int* ptr = &x;
    std::cout << "Value of x via pointer: " << *ptr << std::endl;
    std::cout << "Address stored in ptr: " << ptr << std::endl;
    std::cout << "Size of ptr: " << sizeof(ptr) << std::endl;

    int y = 20;
    ptr = &y; // Reassigning the pointer
    std::cout << "Value of y via reassigned pointer: " << *ptr << std::endl;

    int* nullPtr = nullptr;
    if (nullPtr) { // Checking for null
        // This block will not execute
    }

    // Reference
    int& ref = x;
    std::cout << "Value of x via reference: " << ref << std::endl;
    std::cout << "Size of ref (size of x): " << sizeof(ref) << std::endl;

    // Error: Cannot rebind a reference after initialization
    // int& ref = y;

    // Error: References must be initialized
    // int& invalidRef;

    return 0;
}
-------------------------------------------------------------------------------------
reference is a an alias.  the memory that pointed by reference is same as the memory pointed by the initial variable
Pointer has its own memory, distinct from the memory that it points to.

r-value reference:
    r-value is a temporanry object or value, not represented by a variable.
        e.g a+b,  
        std::string("hello")
        10

    r-value references bind to r-value

        takes template parameter T&& => move constructor and move assignment operator.    

std::forward 
    does forwarding depending of l-value or r-value

    template<T>
    std::forward<T>(args)





 */

/*
    l-value process function is called...
*/
void process(int& x) {
    std::cout << "l-value" << std::endl;
}

void process(int&& x) {
    std::cout << "r-value" << std::endl;
}


template<typename T>
void wrapper(T&& args) {
    process(args);
}


template<typename T>
void wrapper_with_std_forward(T&& args) {
    process(std::forward<T>(args));
}




void std_forward_demo() {
    wrapper(5);
    int x = 2;
    wrapper(x);

    //
    wrapper_with_std_forward(5); //=> this will call the r-value process
    wrapper_with_std_forward(x);
}


void references_demo() {
    int i = 5;
    int* p = &i;
    std::cout << *p << std::endl;

    std::cout << " address of i: " << p << " address of p" << &p << std::endl;

    //address of reference is same as that of the variable
    int& ref_i = i;
    std::cout << " address of ref_i: " << &ref_i << " value: " << ref_i << std::endl;

    int j = 4;
    ref_i = j;
    std::cout << " address of ref_i: " << &ref_i << " value: " << ref_i << std::endl;
    std::cout << " i: " << i << std::endl;    
}


int main()
{
    std_forward_demo();

    //references_demo();
}