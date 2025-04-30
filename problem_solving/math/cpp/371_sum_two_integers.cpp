/*
https://leetcode.com/problems/sum-of-two-integers/
sum = a ^ b 
carry = (a & b) << 1
 */

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // Compute sum without carry
            int sum = a ^ b;
            // Compute carry
            int carry = (a & b) << 1;
            // Update a and b for next iteration
            a = sum;
            b = carry;
        }
        return a;
    }
};