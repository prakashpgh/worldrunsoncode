/*
https://leetcode.com/problems/subarray-sum-equals-k/description/
*/
#include<vector>
#include<iostream>
#include<unordered_map>

int subarray_sum(const std::vector<int>& nums, int k) {
    int count = 0;
    std::unordered_map<int, int> map;
    map[0]=1;
    int sum = 0;
    for(int num : nums) {
        sum += num;
        if(map.find(sum-k) != map.end()) {
            count += map[sum-k];
        }
        map[sum] += 1;
    }
    return count;
}



int main() {
    std::vector<int> nums = {1,1,1};
    int k = 2;
    //Output: 2
    int result = subarray_sum(nums, k);
    std::cout << result << std::endl;

    nums = {1,2,3};
    k = 3;
    //Output: 2
    result = subarray_sum(nums, k);
    std::cout << result << std::endl;
}
