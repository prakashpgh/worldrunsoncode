/*
#https://leetcode.com/problems/4sum/description/

'''
iterate for the 1st..
    iterate for the 2nd
        use 2 pointer for 3rd and 4th
//note that the skip should happen after the match to avoid duplicates
'''
*/
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>


std::vector<std::vector<int>> four_sum(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> results;
    int len = nums.size();
    for(int i = 0; i < len-3; ++i) {
        for(int j = i+1; j < len-2; ++j) {
            int l = j + 1;
            int r = len -1;
            while(l < r) {
                long long sum = nums[i] + nums[j] + nums[l] + nums[r];
                if( sum == target) {
                    results.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l += 1;
                    r -= 1;

                    while(l < r && nums[l] == nums[l-1]) {
                        l += 1;
                    }
                    while(l < r && nums[r] == nums[r+1]) {
                        r -= 1;
                    }
                }  else if(sum > target ) {
                    r -= 1;
                } else {
                    l += 1;
                }
            }
            while(j < len-2 && nums[j] == nums[j+1]) {      //note that the skip should happen after the match
                j += 1;
            }
        }
        while(i < len-3 && nums[i] == nums[i+1]) {
            i += 1;
        }
    }
    return results;
}



int main() {
    std::vector<int> nums;
    nums = {1,0,-1,0,-2,2};
    int target = 0;
    //#Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    auto output = four_sum(nums, target);
    print_vector_of_vector(output);
    std::cout << "----------------------------" << std::endl;
    

    nums = {2,2,2,2,2};
    target = 8;
    output = four_sum(nums, target);
    //print("output: " + str(output))
    //#Output: [[2,2,2,2]]
    print_vector_of_vector(output);
    std::cout << "----------------------------" << std::endl;

    nums={-2,-1,-1,1,1,2,2};
    target=0;
    output = four_sum(nums, target);
    //print("output: " + str(output))
    print_vector_of_vector(output);
    return 0;
}


