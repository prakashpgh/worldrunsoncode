/*'''
https://leetcode.com/problems/maximum-average-subarray-i/
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


double max_average_subarray(std::vector<int>& nums, int k) {
    double max_average = 0;
    for(int i=0; i<k;++i) {
        max_average += nums[i];
    }
    int l =0;
    double current = max_average;
    for(int r = k; r < nums.size(); ++r) {
        current += nums[r];
        while(r-l+1 > k) {
            current -= nums[l];
            l++;
        }
        max_average = std::max(max_average, current);
    }
    return max_average/k;
}


int main() {
    std::vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    //#Output: 12.75000
    double result = max_average_subarray(nums, k);
    std::cout << "result= " << result << std::endl;
}
