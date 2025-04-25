/*
https://leetcode.com/problems/longest-repeating-character-replacement/
sliding window + hashmap

Idea:
    use sliding window... for(r=0)  & l = 0

    to find the valid window: 
        maintain vector(26,0).... (ch[i] - 'A') ... add in the r, - in the l
        window valid = window_len - max_freq > k
*/

#include<iostream>
#include<tuple>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
using namespace std;


int longest_repeating_character_replacement(const std::string& s, int k) {
    int l=0;
    int max_len = 0;
    int len = s.length();
    std::vector alpha_freq(26, 0);
    int max_freq = 0;

    for (int r = 0; r < len; ++r) {
        int char_index = s[r] - 'A';
        alpha_freq[char_index]++;
        max_freq = std::max(max_freq, alpha_freq[char_index]);
        if((r - l + 1) - max_freq > k) {
            //the window is not valid.
            alpha_freq[s[l] - 'A']--;
            l += 1;
        }
        max_len = std::max(max_len, r - l + 1);
    }
    return max_len;
}




int main() {
    std::string input = "ABAB";
    int k = 2;
    //4
    int result = longest_repeating_character_replacement(input, k);
    std::cout << "result: " << result << std::endl;

    //
    input = "AABABBA";
    k = 1;
    //4
    result = longest_repeating_character_replacement(input, k);
    std::cout << "result: " << result << std::endl;
    return 0;
}


