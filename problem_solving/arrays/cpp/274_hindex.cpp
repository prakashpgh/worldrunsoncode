/*
'''
https://leetcode.com/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
approach i => brute force
'''

Approach II: using hashmap
#hindex
#iterate the possible h-indexes 0-N, and try if it works.
#this can start from highest value.  len(nums) = max h-index
#time: O(n)
#space: O(1)
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"

int hindex_bruteforce(const std::vector<int>& nums)
{
    int len = nums.size();
    int hindex = 0;
    for(int i = 0; i < len; ++i ) 
    {
        int count = 0;
        for(int j = 0; j < len; ++j ) {
            if(nums[j] >= i+1) {
                count++;
            }
            if(count == i+1) {
                hindex = std::max(hindex, i+1);
                break;
            }
        }
    }
    return hindex;
}

/*
create a hash of the counts... if the number of citations > no. of paper

go thru the possible hashes from max... 
    check the values from the hash table
    sum the citations..
    if citations > the index number => thats the answer
time O(n)
space O(n)
'''
*/
int hindex_hashmap(const std::vector<int>& nums) {
    //todo
    int hindex = 0;
    return hindex;
}



int main() {
    std::vector<int> nums;
    nums = {5,1,2,8,9,3};
    int h = hindex_bruteforce(nums);
    std::cout << "h=" << h << std::endl;

    h = hindex_hashmap(nums);
    std::cout << "h=" << h << std::endl;
    return 0;
}
