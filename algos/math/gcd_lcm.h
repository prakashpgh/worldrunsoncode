#include<math.h>

int gcd_1(int a, int b) {
    int remain=1;
    int dividend = std::max(a, b);
    int divisor = std::min(a, b);
    while(remain != 0) {
        remain = dividend % divisor;    
        if( remain == 0) {
            break;
        }
        dividend = divisor;
        divisor = remain;
    }
    return divisor;
}


int lcm_1(int a, int b) {
    int remain=1;
    int temp = gcd_1(a, b);
    return (a * b) / temp;
    //return (std::max(a, b)/temp * std::min(a, b));
}


bool is_prime(int num) {
    if(num ==1 )
        return false;
    if(num==2 || num ==3) {
        return true;
    }
    if(num%2 == 0) {
        return false;
    }
    if(num%3 == 0) {
        return false;
    }
    int srt = std::sqrt(num);
    for( int i = 5; i <= srt; i=i+6) {
        if(num % i == 0 || num % (i+2) == 0) {
            return false;
        }
    }
    return true;
}


void print_all_prime_factors(int num) {
    int temp_num = num;
    auto sq = std::sqrt(temp_num);
    for(int i = 0; i < sq; ++i) {
        //is_prime()
    }
}

//divisors will be in pairs:for 15 =>  1,15   3,5     
void all_divisors(int num) {
    for(int i = 1; i*i <= num*num; ++i) {
        if(num % i == 0) {
            std::cout << i << std::endl;
        }    
    }
    for(int i = num*num; i*i <= 2; ++i) {
        if(num % i == 0) {
            std::cout << num/i << std::endl;
        }    
    }
}

void all_prime_numbers_till(int num) {
    std::cout << "naive solution:" << std::endl;
    for(int i = 2; i <= num; ++i) {
        if(is_prime(i)) {
            std::cout << i << std::endl;
        }
    }
}

/**
 make an array of bools..all true
 traverse the array if prime, mark all the mulitples as non-prime
 */
void all_prime_numbers_till_sieve_method(int num) {
    std::cout << "sieve solution:" << std::endl;
    std::vector<bool> is_prime_array(num+1, true);
    for(int i = 2; i <= num; ++i) {
        if(is_prime(i)) {
            std::cout << i << std::endl;
            for(int j = 2*i; j <= num; j=j+i) {
                is_prime_array[j] = false;
            }
        }
    }
}


void all_prime_numbers_till_sieve_method_2(int num) {
    std::cout << "sieve_2 solution:" << std::endl;
    std::vector<bool> is_prime_array(num+1, true);
    for(int i = 2; i <= num; ++i) {
        if(is_prime(i)) {
            std::cout << i << std::endl;
            for(int j = i*i; j <= num; j=j+i) {
                is_prime_array[j] = false;
            }
        }
    }
}