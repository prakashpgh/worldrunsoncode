/*
https://leetcode.com/problems/partition-labels/

Idea:   
    create a map of the character and its last occurence

    now.. iterate the string.  keep a max_index variable
    as you encounter each character, udpate the max_index as the max of last occureces of each of the variable.
    if max_index == i, then we have reached end of one section.
    keep a anchor variable to keep a record of the start of each partition
==================
iterate the string and keep a dictionary of start and end...

now iterate the string,
    update end.. with the end of the character..
    when i == end, the section finishes.. start a new section    

*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
#include<algorithm>
using namespace std;

std::vector<int> partition_labels(const std::string& str) {
    int len = str.length();
    std::vector<int> results;
    std::vector<int> last_occurence(26, 0);
    for(int i = 0; i < len; ++i) {
        last_occurence[str[i] - 'a'] = i;
    }
    //
    int max_occurence = 0;
    int anchor = 0;
    for (int i = 0; i < len; ++i) {
        max_occurence = std::max(max_occurence, last_occurence[str[i] - 'a']);
        if(max_occurence == i) {
            results.push_back(max_occurence - anchor + 1);
            anchor = i + 1;
        }
    }
    return results;
}

    

int main() {
    std::string s = "ababcbacadefegdehijhklij";
    auto result = partition_labels(s);
    print_vector(result);

    s = "eccbbbbdec";
    //#Output: [10]
    result = partition_labels(s);
    print_vector(result);
    return 0;
}
