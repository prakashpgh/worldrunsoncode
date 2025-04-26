/*
https://leetcode.com/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-interview-150

std::unordered_map<std::string, std::vector<std::string>> 
create frequency counter... 
create string key with count#count#...

'''
*/
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
using namespace std;

std::vector<std::vector<string>> group_anagrams(const std::vector<std::string>& strs ) {
    
    std::unordered_map<std::string, std::vector<string>> map;
    for(const auto& str : strs) {
        std::vector<int> key(26, 0);
        for(const auto& ch : str) {
            key[ch - 'a']++; 
        }
        std::string key_str;
        for(int i : key) {
            key_str += std::to_string(i) + "#";
        }
        std::cout << key_str << std::endl;
        map[key_str].push_back(str);
    }

    std::vector<std::vector<string>> result;
    for(const auto& pair : map) {
        result.push_back(pair.second);
    }
    return result;
}




int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> result = group_anagrams(strs);
    print_vector_of_vector(result);
}


