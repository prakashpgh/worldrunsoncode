/*
https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <unordered_map>
#include<string>
#include<iostream>

bool ransom_note(const std::string& ransom_note, const std::string& magazine) {
    std::unordered_map<char, int> mag_map;
    for(const auto ch : magazine ) {
        mag_map[ch] = mag_map[ch]+1;
    }

    for(const auto& ch : ransom_note) {
        if(mag_map.find(ch) != mag_map.end() && 
            mag_map[ch] > 0) {
            mag_map[ch]--;
        } else {
            return false;
        }
    }
    return true;
}


int main() {
    std::string note = "a";
    std::string magazine = "b";
    //Output: false
    auto result = ransom_note(note, magazine);
    std::cout << "result: " << result << std::endl;


    note = "aa";
    magazine = "ab";
    //Output: false
    result = ransom_note(note, magazine);
    std::cout << "result: " << result << std::endl;


    note = "aa";
    magazine = "aab";
    //Output: true
    result = ransom_note(note, magazine);
    std::cout << "result: " << result << std::endl;
}

