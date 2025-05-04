/*
https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

Approach I) Circulate ... around..
            keep the prev.. in variable.
            if the target == start, then break... and set start=start+1

Approach II)
        k = k % len
        reverse whole array
        reverse till k-1
        reverse k to N-1

#todo
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


void rotate_array(std::vector<int>& nums, int k) {

}


void rotate_array_circulate(std::vector<int>& nums, int k) {

}


int main() {
    std::vector<int> nums;
    nums = {1,2,3,4,5,6,7};
    int k = 3;
    //#Output: {5,6,7,1,2,3,4]
    print_vector(nums);
    rotate_array(nums, k);
    print_vector(nums);

    nums = {1,2,3,4,5,6,7};
    print_vector(nums);
    rotate_array_circulate(nums, k);
    print_vector(nums);

    nums = {-1,-100,3,99};
    k = 2;
    //#Output: [3,99,-1,-100]
    print_vector(nums);
    rotate_array(nums, k);
    print_vector(nums);

    nums = {-1,-100,3,99};
    print_vector(nums);
    rotate_array_circulate(nums, k);
    print_vector(nums);
}