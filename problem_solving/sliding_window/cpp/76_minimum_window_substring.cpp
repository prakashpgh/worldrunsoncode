/*
https://leetcode.com/problems/minimum-window-substring/description/?envType=study-plan-v2&envId=top-interview-150

put in hash map

iterate s... r pointer...
    l-pointer => move when 

##good problem
variable to track that the characters and their frequency are same..
    the string character - frequency is stored in a hash map
    variable tracks the number of characters

    in the source string/windows, we maintain a hashmap, and varirable which 
    tracks how many characters match.
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include <iostream>

int minimum_window_substring(const std::string& s, const std::string& t) {
    int result = 0;
    return result;
}

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    //#Output: "BANC"
    //#Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
    result = minimum_window_substring(s, t);
    std::cout << "result: " << result << std::endl;
    
    s = "a";
    t = "a";
    //#Output: "a"
    //#Explanation: The entire string s is the minimum window.
   // #Example 3:
    
    s = "a";
    t = "aa";
    //#Output: ""
    //#Explanation: Both 'a's from t must be included in the window.
    
}
