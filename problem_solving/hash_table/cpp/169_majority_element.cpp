/*
https://leetcode.com/problems/majority-element/
#element which appears more than n/2 times
#Time O(n)
#space O(n)
'''
use dictionary to find the frequency count.
check with freq. count > N//2
'''
*/

#include<iostream>
#include<tuple>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
using namespace std;


int majority_element(const std::vector<int> nums) {
    int len = nums.size();
    std::unordered_map<int, int> freq_map;
    for(int num : nums) {
        freq_map[num]++;
        if(freq_map[num] > len/2) {
            return num;
        }
    }
    return -1;
}


int main() {
    std::vector<int> input;
    input = {3,2,3};
    int result = majority_element(input);
    std::cout << "result: " << result << std::endl;
        

    input = {2,2,1,1,1,2,2};
    result = majority_element(input);
    std::cout << "result: " << result << std::endl;

    input = {3,2,1,1,2,2,2,3,2};
    result = majority_element(input);
    std::cout << "result: " << result << std::endl;
}