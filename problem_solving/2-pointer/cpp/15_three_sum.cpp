/*
https://leetcode.com/problems/3sum/description/?envType=study-plan-v2&envId=top-interview-150

t: O(n)
s: O(1)
#check
iterate ..
    for each element... find the other 2 elements.
    take care of duplicates ..by comparing i+1 and i
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>

std::vector<std::vector<int>> three_sum(std::vector<int>& nums)  {
    std::vector<std::vector<int>> result;
    int target = 0;
    int len = nums.size();
    if(len < 3) {
        return result;
    }
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < len-2; ++i) {
        if(nums[i] > target) {
            break; //since the array is sorted.
        }
        if(i > 0 && nums[i] == nums[i-1]) { //#mistake here
            continue;
        }
        int j = i + 1;
        int k = len - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum == target) {
                result.push_back({nums[i], nums[j], nums[k]});
                while(j < k && nums[j] == nums[j+1]) {      //mistake here
                    j += 1;
                }
                while(j < k && nums[k] == nums[k-1]) {
                    k -= 1;
                }   
                j += 1;
                k -= 1;             
            } 
            else if(sum > target) {
                k -= 1;
            } else {
                j += 1;
            }

        }
    }
    return result;
}

int main() {
    std::vector<int> nums;
    std::vector<std::vector<int>> result;
    nums = {-1,0,1,2,-1,-4};
    result = three_sum(nums);
    print_vector_of_vector(result);
    //#Output: [[-1,-1,2],[-1,0,1]]

    nums = {0,1,1};
    result = three_sum(nums);
    //#Output: []
    print_vector_of_vector(result);

    nums = {0,0,0};
    result = three_sum(nums);
    //#Output: [[0,0,0]]
    print_vector_of_vector(result);

    nums = {-2,0,0,2,2};
    result = three_sum(nums);
    print_vector_of_vector(result);
    return 0;
}

