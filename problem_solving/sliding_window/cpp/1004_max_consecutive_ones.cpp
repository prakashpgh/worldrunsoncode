/*'''
https://leetcode.com/problems/max-consecutive-ones-iii/
sliding windows

'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


int max_consecutive_ones(std::vector<int>& nums, int k) {
    int len = nums.size();
    int zeros = 0;
    int max_len = 0;
    int l = 0;
    for(int r = 0; r < len; ++r) {
        if(nums[r] == 0) {
            zeros++;
        }
        while(zeros > k) {
            if(nums[l] == 0) {
                zeros--;
            }
            l++;
        }
        max_len = std::max(max_len, r-l+1);
    }
    return max_len;
}




int main() {
    std::vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    //#Output: 6
    int result =  max_consecutive_ones(nums, k);
    std::cout << "result: " << result << std::endl;
    
    nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    k = 3;
    //#Output: 10
    result =  max_consecutive_ones(nums, k);
    std::cout << "result: " << result << std::endl;
}
