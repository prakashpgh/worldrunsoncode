#include <vector>
#include <map>
#include "../../utils/utils.h"

std::vector<int> two_sum(const std::vector<int>& nums, int target) {
    std::map<int, int> hashmap;
    int len = nums.size();
    for(auto i = 0; i < len; ++i) {
        if (hashmap.find(target - nums[i]) != hashmap.end()) {
            return {hashmap[target-nums[i]], i};
        } 
        hashmap[nums[i]] = i;
    }
    return {};
}


//print_vector(result);
//Output: [0,1]



/*

*/

int main() {
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    auto result = two_sum(nums, target);
    print_vector(result);

    nums = {3,2,4};
    target = 6;
    result = two_sum(nums, target);
    print_vector(result);
    //utput: [1,2]


    nums = {3,3};
    target = 6;
    result = two_sum(nums, target);
    print_vector(result);
    //Output: [0,1]

}