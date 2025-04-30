/*
'''
https://leetcode.com/problems/remove-letter-to-equalize-frequency/
get all the frequencies in a list

iterate the list
    make a copy of the list.
    remove zeros..
    reduce count of ith
    remaining > 0
    all(x == remaining[0] for all x in remining )

'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


bool remove_letter_to_equalize_frequency(const std::string& word) {
    //get the frequ. of each char of the string
    std::vector<int> freq(26, 0);
    for(auto ch : word) {
        freq[ch - 'a']++;
    }
    int len = word.length();
    //go thru the freq. array, reduce one freq... and using set if there is only one entry i.e all have the same freq.
    for(int i = 0; i < 26; ++i ) {
        if(freq[i] == 0) {
            continue;
        }
        freq[i]--;
        std::set<int> freq_set;
        for(int i = 0; i < 26; ++i ) {
            if(freq[i] == 0) {
                continue;
            }
            freq_set.insert(freq[i]);
        }
        if(freq_set.size() == 1) {
            return true;
        }

        freq[i]++;
    }
    return false;
}
    

int main() {
    return 0;
}