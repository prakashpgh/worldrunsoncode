/*
https://leetcode.com/problems/count-good-triplets/
brute force
    i-loop
    j-loop
    k-loop
        ..check all conditions
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>
#include<algorithm>
using namespace std;


int count_good_triplets(const std::vector<int>& nums, int a, int b, int c)  {
    int l = nums.size();
    int count_triplets = 0;
    for(int i = 0; i < l-2; ++i) {
        for(int j = i+1; j < l-1; ++j) {
            if(std::abs(nums[i] - nums[j]) <= a) {
                for(int k = j+1; k < l; ++k) {
                    if( (std::abs(nums[j] - nums[k]) <= b)  &&  (std::abs(nums[i] - nums[k]) <= c) ) {
                        count_triplets += 1;
                    }
                }
            }
        }
    }
    return count_triplets;
}

int main() {
    return 0;
}