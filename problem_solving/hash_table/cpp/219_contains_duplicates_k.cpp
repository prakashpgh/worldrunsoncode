/*
'''
https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150
#mistake in understanding the problem
    tricky problem
'''
*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


bool contains_duplicates_k(const std::vector<int> nums ) {
    bool result = false;
    return result;
} 


int main()  {
    std::vector<int> nums = {1,2,3,1};
    k = 3;
    //#Output: true
    result = contains_duplicates_k(nums,k);
    std::cout << "contains duplicates: " << result << std::endl;
    
    nums = {1,0,1,1};
    k = 1;
    //#Output: true
    result = contains_duplicates_k(nums,k);
    std::cout << "contains duplicates: " << result << std::endl;    
    
    nums = {1,2,3,1,2,3};
    k = 2;
    //#Output: false;
    result = contains_duplicates_k(nums,k);
    std::cout << "contains duplicates: " << result << std::endl;
        
}

