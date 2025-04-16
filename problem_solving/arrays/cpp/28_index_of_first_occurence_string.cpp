/*
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

1) iterate the whole string
2)  for each char, iterate the needle
*/
#include<string>
#include<iostream>

int index_of_first_occurence_string(const std::string& haystack, const std::string& needle) {
    int h = haystack.length();
    int n = needle.length();
    for (auto i = 0; i < h-n+1; ++i ) {
        int j = 0;
        for (j = 0; j < n; ++j) {
            if(haystack[i+j] != needle[j]) {
                break;
            }
        }
        std::cout << "j:" << j << std::endl;
        if(j==n) {
            
            return i;
        }
    }
    return -1;
}




int main() {
    std::string haystack = "sadbutsad";
    std::string needle = "sad";
    int index = index_of_first_occurence_string(haystack, needle);
    std::cout << "result: " << index << std::endl;
    //0


    haystack = "leetcode";
    needle = "leeto";
    //Output: -1
    index = index_of_first_occurence_string(haystack, needle);
    std::cout << "result: " << index << std::endl;
}