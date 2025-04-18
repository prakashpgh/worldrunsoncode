/*
https://leetcode.com/problems/word-break/description/
*/

#include<vector>
#include<string>
#include<unordered_set>
#include<iostream>


bool recur(const std::string& s, const std::unordered_set<std::string>& words, std::vector<int>& dp, int index) {
    int len=s.length();
    if(dp[index] != -1) {
        return dp[index];
    }
    if(index==len) {
        dp[index] = true;
        return dp[index];
    }
    
    for(int i = index; i < len; ++i) {
        if( words.find(s.substr(index, i-index+1)) != words.end() && 
            recur(s, words, dp, i + 1)) {
                dp[index] = true;
                return dp[index];
        }
    }
    dp[index] = false;
    return dp[index];
} 


bool word_break(const std::string& s, const std::vector<std::string>& words) {
    std::unordered_set<std::string> words_dict;
    
    std::vector<int> dp(s.length() + 1, -1);
    for(const auto& word : words) {
        words_dict.insert(word);
    }

    return recur(s, words_dict, dp, 0);
}


int main() {
    std::string s = "leetcode";
    std::vector<std::string> words = {"leet", "code"};
    bool result = word_break(s, words);
    std::cout << "result: " << result << std::endl;
    //true

    s = "catsandog";
    words = {"cats","dog","sand","and","cat"};
    result = word_break(s, words);
    std::cout << "result: " << result << std::endl;
    //false

    s = "applepenapple";
    words = {"apple","pen"};
    //Output: true
    result = word_break(s, words);
    std::cout << "result: " << result << std::endl;

}