/*
https://leetcode.com/problems/powx-n/


*/

#include<iostream>

double my_pow(double x, int n) {
    if(n == 0 ) {
        return 1;
    }
    long long ln = n;   //#mistake need this to avoid issues with large -ve numbers
    if(ln < 0) {
        x = 1/x;
        ln = -ln;
    }
    if(ln % 2 == 0) {
        return my_pow(x*x, ln/2);
    } else {
        return x * my_pow(x, ln-1);
    }
}


double my_pow_iterative(double x, int n) {
    if(n == 0 ) {
        return 1;
    }
    long long ln = n;   //#mistake need this to avoid issues with large -ve numbers
    if(ln < 0) {
        x = 1/x;
        ln = -ln;
    }
    double result = 1.0;
    double current = x;
    while(ln > 0) {
        if(ln % 2 == 1) {
            result *= current;
        }
        current *= current;
        ln /= 2;   
    }
    return result;
}


int main() {
    double x = 2;
    int n = 10;
    auto result = my_pow(x, n);
    std::cout << "result: " << result << std::endl;
}