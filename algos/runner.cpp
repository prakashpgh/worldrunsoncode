#include<cstdio>
#include "two_sum.h"
#include "two_sum.h"
#include <iostream>
#include "stock_price.h"
#include "array_duplicate_check.h"
#include "multiply_others.h"
#include "math/fibonacci.h"
#include "math/count_digits.h"
#include "math/palindrome_number.h"
#include "math/factorial.h"
#include "math/gcd_lcm.h"
#include "math/compute_power.h"


print_vector(const std::vector<int> result)
{
    std::cout << "[";
    int len = result.size();
    for( int i = 0; i < len; ++i ) {
        std::cout << result[i] << ",";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    /*
    bool isPrime = is_prime(101);
    std::cout << "isPrime: " << isPrime;
    */

    /*
    int a = 4;
    int b = 6;

    int gcd = gcd_1(a, b);
    std::cout << "gcd: " << a << "," << b << "="<< gcd << std::endl;
    
    a = 25;
    b = 135;
    int lcm = lcm_1(a, b);
    std::cout << "lcm: " << a << "," << b << "=" << lcm << std::endl;
    
    a = 24;
    b = 32;
    lcm = lcm_1(a, b);
    std::cout << "lcm: " << a << "," << b << "="<< lcm << std::endl;

    a = 25;
    b = 135;
    lcm = lcm_1(a, b);
    std::cout << "lcm: " << a << "," << b << "="<< lcm << std::endl;

    a = 2;
    b = 8;
    lcm = lcm_1(a, b);
    std::cout << "lcm: " << a << "," << b << "="<< lcm << std::endl;
    */

    /*
    int gcd = gcd_1(4,6);
    gcd = gcd_1(25, 135);
    gcd = gcd_1(24, 32);
    std::cout << "gcd: " << gcd;
    */

    /*
    int trailingZeros = trailing_zeros_in_factorial_naive_solution(10);
    std::cout << "trailing_zeros: " << trailingZeros;
    */

    /*
    int trailingZeros = trailing_zeros_in_factorial(251);
    std::cout << "trailing_zeros: " << trailingZeros;
    */

    /*
    int fact = factorial_iterative(4);
    std::cout << "factorial_iterative: " << fact << std::endl;
    */
    /*
    int fact = factorial_recursive(4);
    std::cout << "fact: " << fact << std::endl;
    */
    /*
    int digits = count_digits(9235);
    std::cout << "digits: " << digits;
    */
    /*
    int N = 10;
    init_memo(N);
    int ans = fibonacci_iter(6);
    std::cout << "fibonacci: " << ans;
    return 0;
    */

    /*
   int N = 10;
    init_memo(N);
    int ans = fibonacci_memo(6);
    std::cout << "fibonacci_memo: " << ans;
    return 0;
    */

    /*
    int ans = fibonacci_recursion(6);
    std::cout << "fibonacci_recursion: " << ans;
    return 0;
    */
 
    /*
    std::vector<int> input {1, 2, 3, 4};
    std::vector<int> result = productExceptSelf(input);
    print_vector(result);
    return 0;
    */

    /*
    std::vector array {1,2,3,1};
    bool dup = duplicate_check(array);
    std::cout << "duplicate: " << dup;
    return 0;
*/

/*
    printf("hello\n");
    std::vector prices {7,1,5,3,6,4};
    find_profit(prices);
    return 0;
*/

/*
    //TwoSum twoSum;
    std::vector vec {1,4, 5, 6,3};
    auto result = twoSum.twoSum(vec, 9);
    for(int i : result) {
        std::cout << vec[i] << std::endl;
    }
    return 0;
    */

    /*
    /all divisors
    all_divisors(18);
    **/

    /** */
    
    /*
    all_prime_numbers_till(15);   

    all_prime_numbers_till_sieve_method(15);

    all_prime_numbers_till_sieve_method_2(15);
    */

    std::cout << "compute_power_recursive: " << std::endl;
    std::cout << compute_power_recursive(3, 5) << std::endl;

    std::cout << "compute_power_iterative: " << std::endl;
    std::cout << compute_power_iterative(3, 5) << std::endl;
}
