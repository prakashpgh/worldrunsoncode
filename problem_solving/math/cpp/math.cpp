#include<iostream>

//gets the number of digits
//O(N)
int digits_count(int num)
{
    int digits = 0;
    while(num>0)
    {
        num /= 10;
        digits++;
    }
    return digits;
}

//sum of digits
int sum_digits(int num)
{
    int sumDigits = 0;
    while(num>0)
    {
        sumDigits += num % 10;
        num /= 10;
    }
    return sumDigits;
}

int reverse_number(int num)
{
    int result = 0;
    while(num>0)
    {
        int digit = num % 10;
        result = result*10 + digit;
        num /= 10;
    }
    return result;
}


bool is_palindrome(int num)
{
    bool isPalindrome = false;
    int reverseNumber = reverse_number(num);
    isPalindrome = (num == reverseNumber);
    return isPalindrome;
}

//O(N)
//Space O(1)
int factorial_iterative(int num)
{
    int fact = 1;
    for(int i = 2; i < num+1; ++i)
    {
        fact *= i;
    }
    return fact;
}

//O(N)
//space=O(N)
int factorial_recursive(int num)
{
    if(num < 0 )
        throw ("the argument is not valid");
    if(num <= 1)
        return 1;
    return num * factorial_recursive(num-1);
}


int main()
{
    int digits = digits_count(1234567);
    std::cout << "digits: " << digits << std::endl;

    int sumDigits = sum_digits(567);
    std::cout << "sum of digits: " << sumDigits << std::endl;

    int reverseNumber = reverse_number(567);
    std::cout << "reverse number: " << reverseNumber << std::endl;

    bool isPalindrome = is_palindrome(1234321);
    std::cout << "isPalindrome: " << isPalindrome << std::endl;

    int factorial = factorial_iterative(5);
    std::cout << "factorial-iterative: " << factorial << std::endl;
    
    factorial = factorial_recursive(5);
    std::cout << "factorial-recursive: " << factorial << std::endl;
    return 0;
}