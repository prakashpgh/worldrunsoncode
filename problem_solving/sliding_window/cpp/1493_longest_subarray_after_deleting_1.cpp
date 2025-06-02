/*'''
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

sliding window
r- for loop
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


int longest_subarray_after_deleting_ones(std::vector<int>& nums) {
    int len = nums.size();
    int l = 0;
    int longest = 0;
    int zeros = 0;
    for(int r = 0; r < len; ++r) {
        if(nums[r] == 0) {
            zeros++;
        }
        while(zeros > 1) {
            if(nums[l] == 0) {
                zeros--;
            }
            l++;
        }
        longest = std::max(longest, r-l);//r-l+1 -1 => since we need to delete 1 
    }
    return longest;
}

int main() {
    std::vector<int> nums = {1,1,0,1};
    //#Output: 3
    int result = longest_subarray_after_deleting_ones(nums);
    std::cout << "result= " << result << std::endl;
    
    nums = {0,1,1,1,0,1,1,0,1};
    //#Output: 5
    result = longest_subarray_after_deleting_ones(nums);
    std::cout << "result= " << result << std::endl;
    
    
    nums = {1,1,1};
    //#Output: 2
    result = longest_subarray_after_deleting_ones(nums);
    std::cout << "result= " << result << std::endl;
}
