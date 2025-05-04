/*
'''
https://leetcode.com/problems/word-pattern/description/?envType=study-plan-v2&envId=top-interview-150

'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


bool word_pattern(const std::string& pattern, const std::string& s)  {
    bool result = false;
    return result;
}



int main() {
    std::string pattern = "abba";
    std::string s = "dog cat cat dog";
    //#Output: true
    bool result = word_pattern(pattern,s);
    std::cout << "result: " << result << std::endl;
    
    pattern = "abba";
    s = "dog cat cat fish";
    //#Output: false
    result = word_pattern(pattern,s);
    std::cout << "result: " << result << std::endl;
    
    pattern = "aaaa";
    s = "dog cat cat dog";
    //#Output: false
    result = word_pattern(pattern,s);
    std::cout << "result: " << result << std::endl;
    
}
