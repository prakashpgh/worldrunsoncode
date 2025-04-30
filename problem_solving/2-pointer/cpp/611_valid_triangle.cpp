/*
'''
https://leetcode.com/problems/valid-triangle-number/
    sort the array
    consider the longest side from the array..  as 2nd index.. since [0] and [1] will be smaller
    now using 2-pointer technique, from 0 to k-1, 
    l = 0 
    r = k-1
        if less, then i++
        else,
            j-i possible combinations 
            j--
#partly 2-pointer and partly binary search
#revisit
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


int triangle_number(std::vector<int>& nums)  {
    int len = nums.size();
    int count = 0;
    if(len < 3) {
        return count;
    }
    std::sort(nums.begin(), nums.end());
    //k from 2 to 
    for(int k = 2; k < len; ++k ) {
        int i = 0;
        int j = k-1;
        while(i < j) {
            if(nums[i] + nums[j] > nums[k]) {
                count += j -i; //for all values from i+1, j  ...i+2, j  j-1, j
                j -= 1;
            } else {
                i += 1;
            }
        }
    }
    return count;
}

int main() {
    std::vector<int> nums;
    nums = {2,2,3,4};
    //Output: 3
    int result = triangle_number(nums);
    std::cout << "result: " << result << std::endl;

    nums = {4,2,3,4};
    //#Output: 4;
    result = triangle_number(nums);
    std::cout << "result: " << result << std::endl;
    return 0;
}
    