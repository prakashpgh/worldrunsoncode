/*
https://leetcode.com/problems/split-array-largest-sum/
*/

#include<queue>
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<stack>
#include<numeric>
#include<algorithm>


int split_arrays(const std::vector<int>& nums, int k) {
    long long l = *std::max_element(nums.begin(), nums.end());
    long long r = std::accumulate(nums.begin(), nums.end(), 0LL);

    while(l < r) {
        long long m = l + (r-l)/2;
        long long current_sum = 0;
        int partitions = 1;
        for(int n : nums ) {
            if(current_sum + n <=m) {
                current_sum += n;
            } else {
                current_sum = n;
                partitions += 1;
            }
        }
        if( partitions > k) {
            l = m+1;
        } else {
            r = m;
        }
    }
    return l;
}


int main() {
    std::vector<int> nums = {5, 1, 2, 7, 3, 4};
    int k = 3;
    int max_sum = split_arrays(nums, k);
    std::cout << "max_sum: " << max_sum << std::endl;
    return 0;
}