/* 
2176_equal_divisible_pairs.cpp

Approach I:
    brute force
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>
#include<algorithm>
using namespace std;


int count_pairs_brute_force(std::vector<int>& nums, int k)
{
    int len = nums.size();
    int pairs = 0;
    for(int i = 0;i < len; ++i) {
        for(int j = i+1;j < len; ++j) {
            if(nums[i] == nums[j] && ( (i * j) % k == 0 ) ) {
                pairs += 1;
            }
        }
    }
    return pairs;
}


int main() {
    return 0;
}