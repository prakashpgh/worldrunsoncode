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

    //#remove the rightmost 1 =>  x & (x-1)
    x = 5;
    std::bitset<32> binary(x);
    std::cout << "binary " << x << "=>" << binary << std::endl;    
    x = x & (x-1);
    binary = x;
    std::cout << "binary " << x << "=>" << binary << std::endl;    

    //#number of 1s in x = ones in [x & (x-1)] + 1
    
    //number of ones in x = 
    //  if x = even, ones(x / 2) => for even number, the last bit is is 0, so right shift by 1 => divide by 1.
    //  if x = odd, 1 + ones(x/2) => for odd number, the last bit is is 1, so right shift by 1 => divide by 1.
    


    unsigned long num = binary.to_ulong();
    std::cout << "decimal " << binary << "=>" << num << std::endl;    


    std::string binaryString = "1011001";
    std::bitset<32> bs(binaryString); // Specify the size of the bitset
    num = bs.to_ulong();
    std::cout << "decimal " << binaryString << "=>" << num << std::endl;    

    //traversing the bits.
    num = 45;
    std::cout << num << " => ";
    for(int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        std::cout << bit;
    }
    std::cout << std::endl;

    //toggling the bits
    //changing 45 to 41..
    num = 45;
    num = num ^ (1 << 2);
    std::cout << num << std::endl;
}


void and_range_of_numbers(int left, int right) {
    while(left < right) {
        right = right & (right - 1);
    }
    std::cout << "&range " << right << std::endl;
}







int main() {
    //bit_magic();

    and_range_of_numbers(5,7);
    and_range_of_numbers(9,12);

    return 0;
}

      






