/*
https://leetcode.com/problems/merge-strings-alternately/

while(i < s1.length() || j < s2.length() ) {
    
}
*/

#include<iostream>
#include<tuple>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
using namespace std;


std::string merge_strings_alternately(const std::string& s1, const std::string& s2)  {
    int l1= s1.length();
    int l2 = s2.length();
    std::string result;
    result.reserve(l1+l2);

    int i = 0;
    int j = 0;
    int k = 0;
    while(i < l1 || j < l2) {
        if(i < l1) {
            result += s1[i];
            i += 1;
        }
        if(j < l2) {
            result  += s2[j];
            j += 1;
        }
        k += 1;
    }
    return result;
}


int main() {
    std::string word1 = "abc";
    std::string word2 = "pqr";
    //#Output: "apbqcr";
    std::string result = merge_strings_alternately(word1, word2);
    std::cout << result << std::endl;


    word1 = "ab";
    word2 = "pqrs";
    //#Output: "apbqrs"
    result = merge_strings_alternately(word1, word2);
    std::cout << result << std::endl;

    word1 = "abcd";
    word2 = "pq";
    //#Output: "apbqcd"
    result = merge_strings_alternately(word1, word2);
    std::cout << result << std::endl;
    return 0;
}
