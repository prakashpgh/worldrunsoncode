#include <iostream>

/**
 * reference is a const pointer, with default indirection,
 Use references whereever possible.

reference is a an alias.  the memory that pointed by reference is same as the memory pointed by the initial variable
Pointer has its own memory, distinct from the memory that it points to.


 */

int main()
{
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