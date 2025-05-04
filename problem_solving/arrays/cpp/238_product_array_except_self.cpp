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
    std::vector<int> result;
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


    input = {1,2,3,4};
    result = product_of_array_except_self(input);
    print_vector(result);

    input = {-1,1,0,-3,3};
    result = product_of_array_except_self(input);
    print_vector(result);


    input = {1,2,3,4};
    result = product_of_array_except_self(input);
    print_vector(result);

    input = {-1,1,0,-3,3};
    result = product_of_array_except_self(input);
    print_vector(result);
    return 0;
}