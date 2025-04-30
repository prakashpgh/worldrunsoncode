/*
https://leetcode.com/problems/shortest-word-distance/description/
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


int shortest_word_distance(std::vector<std::string>& words_dict, const std::string& word1, const std::string& word2) {
    int len = words_dict.size();
    int w1 = -1;
    int w2 = -1;
    int min_dist = INT_MAX;
    for(int i = 0; i < len; ++i)  {
        if(words_dict[i] == word1) {
            w1 = i;
            if(w2 >= 0) {
                min_dist = std::min(min_dist, abs(w2-w1));
            }
        } else if(words_dict[i] == word2) {
            w2 = i;
            if(w1 >= 0) {
                min_dist = std::min(min_dist, abs(w2-w1));
            }
        } 
    }
    return min_dist;
}


int main() {
    return 0;
}