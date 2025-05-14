/*
https://leetcode.com/problems/increasing-triplet-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

#tricky
iterate the numbers
    keep updating first to its lowest
    else keep updating second to its lowest
*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


bool increasing_triplet_sequence(std::vector<int>& nums) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for(int i : nums) {
        if(i <= min1) {
            min1 = i;
        } else if( i <= min2) {
            min2 = i;
        } else {
            return true;
        }
    }
    return false;

}
        




int main() {
    std::vector<int> nums = {1,2,3,4,5};
    //#Output: true
    //#Explanation: Any triplet where i < j < k is valid.
    bool result = increasing_triplet_sequence(nums);
    std::cout << "result:" << result << std::endl;
    
    
    nums = {5,4,3,2,1};
    //#Output: false
    result = increasing_triplet_sequence(nums);
    std::cout << "result:" << result << std::endl;
    
    
    nums = {2,1,5,0,4,6};
    //#Output: true
    result = increasing_triplet_sequence(nums);
    std::cout << "result:" << result << std::endl;
}
