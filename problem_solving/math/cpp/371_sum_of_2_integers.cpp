/*
https://leetcode.com/problems/sum-of-two-integers/
*/

int sum_of_2_integers(int a, int b)  {
    while(b != 0) {
        uint32_t carry = a & b;//carry
        a = a ^ b;  //add without carry
        b = carry << 1;//shift carry to left by one
    }
    return a;
} 

int main() {

    return 0;
}