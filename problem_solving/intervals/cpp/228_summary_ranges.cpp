/*
https://leetcode.com/problems/summary-ranges/
*/
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include "../../utils/utils.h"
using namespace std;


std::vector<std::string> summary_ranges(const std::vector<int> nums) {
    int l = nums.size();
    std::vector<std::string> results;
    if (nums.empty()) {
        return results;
    }
    int start = 0;
    
    for(int i = 1; i < l; ++i) {
        if (nums[i] > (nums[i-1] + 1 ) ) {
            std::stringstream ss;
            ss << nums[start];
            if (i-1 > start) {
                ss << "=>" << nums[i-1];
            } 
            start = i;
            results.push_back(ss.str());
        }
        if(i==l-1) {
            std::stringstream ss;
            ss << nums[start];
            if (i > start) {
                ss << "=>" << nums[i];
            }
            results.push_back(ss.str());
        }
    }
}


int main() {
    std::vector<int> nums = {0,1,2,4,5,7};
    //Output: ["0->2","4->5","7"]
    std::vector<std::string> result = summary_ranges(nums);
    print_vector(result);

    nums = {0,2,3,4,6,8,9};
    //Output: ["0","2->4","6","8->9"]
    result = summary_ranges(nums);
    print_vector(result);

}