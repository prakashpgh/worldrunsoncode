/*
Given two strings S and W. Find the number of times W appears as a subsequence of string S where repeat of character of string S can be included in forming at most one subsequence.
repeat of character of string is allowed

#todo
*/

/*
https://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/
Given two strings S and W. Find the number of times W appears as a subsequence of string S where every character of string S can be included in forming at most one subsequence.

recursion..
Choices:
    start from the end..
    the last characters match
    O
    the last characters dont match
*/

#include<string>
#include<iostream>
#include "../../utils/utils.h"



int number_substrings_no_repeatition(const std::string& a, const std::string& b, int len_a, int len_b) {
    if((len_b==0 && len_a==0) || len_b==0)    {
        return 1;
    }
    if(len_a==0) {
        return 0;
    }
    if (a[len_a-1] == b[len_b-1]) {
        return number_substrings(a, b, len_a-1, len_b-1);
    } else {
        return number_substrings(a, b, len_a-1, len_b);
    }
}



int main() {
    std::string a = "GeeksforGeeks";
    std::string b = "Gks";
    //Output: 4
    int result = number_substrings(a, b, a.size(), b.size());
    std::cout << "result: " << result << std::endl;

}

