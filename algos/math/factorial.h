//O(n)
//space: O(n)
int factorial_recursive(int num) {
    if(num == 1) {
        return 1;
    } else {
        return num*factorial_recursive(num-1);
    }
}

//O(n)
//space: O(1)
int factorial_iterative(int num) {
    int fact = 1;
    for(int i=1;i <= num; ++i)  {
        fact = fact*i;
    }
    return fact;
}


int trailing_zeros_in_factorial_naive_solution(int num) {
    int zeros = 0;
    int fact = 1;
    for(int i = 2; i <= num; ++i) {
        fact *= i;
    }
    std::cout << "fact: " << fact;
    while(fact%10==0) {
        zeros++;
        fact = fact / 10;
    }
    return zeros;
}

//to get zeros, you have to find number of 5 as factors... e.g 10! will have 5 & 10 => 2..   10/5 = 2
//similarly we have to try for 25 ...
int trailing_zeros_in_factorial(int num) {
    int trailingZeros = 0;
    int divisor = 5;
    while(num / divisor >= 1) {
        trailingZeros += num / divisor;
        divisor *= 5;
    }
    return trailingZeros;
}