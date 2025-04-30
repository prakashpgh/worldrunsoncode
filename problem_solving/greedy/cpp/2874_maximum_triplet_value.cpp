/*
https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>
#include<algorithm>
using namespace std;


long long maximum_triplet_value(std::vector<int>& nums)  {
    long long max_diff = 0;
    long long max_num = nums[0];
    long long max_triplet = 0;
    int len = nums.size();
    if(len < 3){
        return 0;
    }

    for (int j = 1; j < len; ++j) {
        //diff
        max_diff = std::max(max_diff, max_num - (long long)nums[j]);

        //triplet
        if(j < len-1) {
            max_triplet = std::max( max_triplet, max_diff * nums[j+1]);
        }

        //num[i]
        max_num = std::max( max_num, (long long)nums[j]);
    }
    return max_triplet;
}

int main() {
    return 0;
}