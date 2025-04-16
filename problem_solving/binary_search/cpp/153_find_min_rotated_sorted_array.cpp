#include<vector>
#include<iostream>


int find_min_rotated_sorted_vector(const std::vector<int>& nums) {
    int l = 0;
    int r = nums.size()-1;
    while(l < r) {
        int m = l + (r-l)/2;
        if(nums[m] > nums[r]) {
            l = m+1;
        } else {
            r = m;
        }
    }
    return nums[l];
}


int main() {
    std::vector<int> nums = {11,12,13,14,15,8,9,10};
    std::cout << "find min element in the rotated sorted array:" << std::endl;
    int result = find_min_rotated_sorted_vector(nums);
    std::cout << result << std::endl;
}