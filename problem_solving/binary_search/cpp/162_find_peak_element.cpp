/*'''
https://leetcode.com/problems/find-peak-element/

use binary search
if n(m) > n(m+1), search the lhs, else rhs

O(log N)
'''*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
#include<math.h>

int find_peak_element(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}





int main() {
    std::vector<int> nums = {1,2,3,1};
    //#Output: 2
    int result = find_peak_element(nums);
    std::cout << "result: " << result << std::endl;
    
    
    nums = {1,2,1,3,5,6,4};
    //#Output: 5
    result = find_peak_element(nums);
    std::cout << "result: " << result << std::endl;
    
}
