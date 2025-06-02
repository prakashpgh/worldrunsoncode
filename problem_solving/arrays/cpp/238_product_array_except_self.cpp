/*
'''
https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150

Approach I:
    using pre and post arrays.

Approach II:
    using only one array

'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
//todo


std::vector<int>  product_of_array_except_self(const std::vector<int>& nums) {
    int len = nums.size();
    std::vector<int> result(len, 1);
    for(int i = 1; i < len; ++i) {
        result[i] = result[i-1] * nums[i-1];
    }
    int mult = 1;
    for(int i = len-2; i >= 0; --i) {
        mult *= nums[i+1];
        result[i] *= mult;
    }
    return result;
}

int main() {
    std::vector<int> input;
    input = {1,2,3,4};
    std::vector<int> result = product_of_array_except_self(input);
    print_vector(result);

    input = {-1,1,0,-3,3};
    result = product_of_array_except_self(input);
    print_vector(result);
    return 0;
}