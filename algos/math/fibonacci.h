/**
 0  1   1    2  3   5   8   13
 */

int fibonacci_recursion(int n) {
    if(n < 0) {
        throw "invalid input: ";
    }
    if(n < 2) {
        return 1;
    }
    return fibonacci_recursion(n-1) + fibonacci_recursion(n-2);
}

int* memo = NULL;
void init_memo(int n) {
    memo = new int[n];
    for(int i = 0; i < n; ++i) {
        memo[i] = -1;
    }
}



int fibonacci_memo(int n) {
    if(memo[n] != -1) {
        return memo[n];
    }
    if(n < 0) {
        throw "invalid input: ";
    }
    if(n < 2) {
        return 1;
    }
    int fib = fibonacci_recursion(n-1) + fibonacci_recursion(n-2);
    memo[n] = fib;
    return fib;
}


int fibonacci_iter(int n) {
    if(n < 2) {
        return 1;
    }
    std::vector<int> vec;
    vec.reserve(n+1);

    vec[0] = 1;
    vec[1] = 1;
    for (int i = 2; i < n+1; ++i) {
        vec[i] = vec[i-1] + vec[i-2];
    }
    return vec[n];
}



