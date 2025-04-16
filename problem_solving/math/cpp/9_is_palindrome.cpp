/*
https://leetcode.com/problems/palindrome-number/

note you dont have to fully reverse the number.
better option it to reverse the second half...  till the rev_number > original num..
*/
#include<iostream>

bool is_number_palindrome(int number) {
    if ((number < 0) || (number %10 == 0 && x !=0)) {
        return false;
    }
    int rev_number = 0;
    while (rev_number <= number ) {
        rev_number = rev_number*10 + number % 10;
        if(rev_number == number) {
            return true;
        }
        number /= 10;
        if(rev_number == number) {
            return true;
        }
    }
    return false;
}



int main() {
    int num = 12321;
    bool result = is_number_palindrome(num);
    std::cout << "result: " << result << std::endl;

    num = 123216;
    result = is_number_palindrome(num);
    std::cout << "result: " << result << std::endl;

    num = 11;
    result = is_number_palindrome(num);
    std::cout << "result: " << result << std::endl;
    return 0;
}