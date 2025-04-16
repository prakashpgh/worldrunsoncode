#include<vector>
#include<iostream>

int find_min_index_duplicates_rotated_sorted_vector(const std::vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while(l < r) {
        int m = l + (r-l)/2;
        if(nums[m] > nums[r]) {
            l = m + 1;
        } else if(nums[m] < nums[r]) {
            r = m;
        } else {
            //here ==, so we are reducing r to remove one of the duplicates.
            r -= 1;
        }
    }
    return nums[l];
}


int main() {
    std::vector<int> nums = {1,3,5};
    //Output: 1
    int result = find_min_index_duplicates_rotated_sorted_vector(nums);
    std::cout << result << std::endl;


    nums = {2,2,2,0,1};
    result = find_min_index_duplicates_rotated_sorted_vector(nums);
    std::cout << result << std::endl;
    //Output: 0
}
