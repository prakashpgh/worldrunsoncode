/*
https://leetcode.com/problems/factorial-trailing-zeroes/

iterate the numbers... for each number, see how many 5s are present.
*/
#include<iostream>

int factorial_trailing_zeros(int n) {
    int zeros = 0;
    for (int i=1; i<=n; ++i) {
        int n = i;
        while(n > 0 && n % 5 == 0) {
            zeros += 1;
            n = n / 5;
        }
    }
    return zeros;
}


int factorial_trailing_zeros(int n) {
    int zeros = 0;
    while(n > 0) {
        n /= 5;
        count += n;
    }
    return count;
}

int main() {
    int n = 3;
    int result = factorial_trailing_zeros(n);
    std::cout << "result: " << result << std::endl;

    n = 5;
    result = factorial_trailing_zeros(n);
    std::cout << "result: " << result << std::endl;

    n = 0;
    result = factorial_trailing_zeros(n);
    std::cout << "result: " << result << std::endl;
}
