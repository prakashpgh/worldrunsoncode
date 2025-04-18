#include<iostream>
#include<bitset>

void bit_magic() {
    //xor with the same number gives zero
    int p = 25;
    std::cout << (p ^ p) << std::endl;

    //right shift divides by 2
    int y = 28;
    std::cout << (y >> 1) << std::endl;

    //left shift multiplies by 2
    y = 28;
    std::cout << (y << 1) << std::endl;    

    //#to obtain lsb, & 1
    int x = 5;
    std::cout << "lsb " << x << "=>" << (x & 1) << std::endl;    

    //#check number is even.
    int n = 24;
    bool is_even = (n & 1) == 0;
    std::cout << "even " << n << "=>" << is_even << std::endl;    

    //#check number is odd.
    n = 21;
    bool is_odd = (n & 1) == 1;
    std::cout << "odd " << n << "=>" << is_odd << std::endl;    

    //#remove the rightmost 1
    x = 5;
    std::bitset<32> binary(x);
    std::cout << "binary " << x << "=>" << binary << std::endl;    
    x = x & (x-1);
    binary = x;
    std::cout << "binary " << x << "=>" << binary << std::endl;    

    //#number of 1s in x = ones in [x & (x-1)] + 1
    
    
    unsigned long num = binary.to_ulong();
    std::cout << "decimal " << binary << "=>" << num << std::endl;    
}


int main() {
    bit_magic();
    return 0;
}

      






