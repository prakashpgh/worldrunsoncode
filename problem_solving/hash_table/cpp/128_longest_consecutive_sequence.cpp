/*
#Approach I: n log N => sort and then find the consecutive sequence

#Approach II: insert the list into has set
#if the N has N-1 has set, then ignore.
    #if it does not, then keep looking for the numbers above it.
#check for the element which starts the sequence ... 
#O(n)
#space O(n)
#interesting
*/

#include<iostream>
#include<tuple>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
using namespace std;


int longest_consecutive_sequence(const std::vector<int>& nums)  {
    std::unordered_set<int> sequence;
    for(int num : nums) {
        sequence.insert(num);
    }
    int max_len = 0;
    for(int num : sequence) {
        if (sequence.find(num-1) == sequence.end()) {
            int len = 1;
            while( sequence.find(num+1) != sequence.end() ) {
                len += 1;  
                num=num+1;  
            }
            max_len = std::max(max_len, len);
        }
    }
    return max_len;
}


int main() {
    std::vector<int> input;
    input = {100, 4, 200, 1,3,2};
    auto result = longest_consecutive_sequence(input);
    std::cout << "result=" << result << std::endl;
    //4

    input = {0,3,7,2,5,8,4,6,0,1};
    result = longest_consecutive_sequence(input);
    std::cout << "result=" << result << std::endl;
    //9

    input = {1,0,1,2};
    //Output: 3
    result = longest_consecutive_sequence(input);
    std::cout << "result=" << result << std::endl;
    //3
}


