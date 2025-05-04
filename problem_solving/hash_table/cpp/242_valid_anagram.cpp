/*
'''
https://leetcode.com/problems/valid-anagram/description/?envType=study-plan-v2&envId=top-interview-150

approach i: sort the strings and the strings should be identical
lengths should be same

#meta
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


bool valid_anagram(const std::string& s, const std::string& t) {
    bool result = false;
    return result;
}


int main() {
    std::string s = "anagram";
    std::string t = "nagaram";
    bool result = valid_anagram(s, t);
    std::cout << "result: " << result << std::endl;
    //#True
    
    s = "rat";
    t = "car";
    result = valid_anagram(s, t);
    std::cout << "result: " << result << std::endl;
    //#False
    
}