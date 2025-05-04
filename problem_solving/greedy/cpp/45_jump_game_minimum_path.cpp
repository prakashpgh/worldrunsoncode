/*
'''
https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150
'''
'''
Analogry of a BSF... level search 
    => how far we can go with the current jump... traverse till there.. like a level in BSF
    => how far we we can go while traversing these nodes.

Idea is to divide the whole into ranges.... each range is reached by a jump [min, max]
first range is the first stair case.
    Now you can jump to different stairs. 1..max_jump   
    these for the range.  the farthest is the max of this range... which is end variable.  
    so this range has [begin... end]
    
    from each of the stairs in that range, we find the farthest we can jump.
        when we tried the jump from end, that range is finished.  
            => Now we get the next range, and our jumpo count is updated, and the end of the next range is updated
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


int jump_minimum_greedy(const std::vector<int>& nums)  {
    if(nums.size() <=1) {
        return 0;
    }
    int jumps = 0;
    int max_reach = 0;
    int current_reach = 0;
    for(int i = 0; i < nums.size(); ++i) {
        max_reach = std::max(max_reach, i+nums[i]);
        if(i==current_reach) {
            jumps++;
            current_reach = max_reach;
            if(current_reach >= nums.size() - 1) {  //#important to have check here.
                return jumps;
            }
        }
    }

    return jumps;
}

        


int main() {
    std::vector<int> nums;
    nums =  {1,1,2,5,2,1,0,0,1,3};
    int result = jump_minimum_greedy(nums);
    std::cout << "result-recur: " << result << std::endl;


    nums =  {2,3,1,1,4};
    result = jump_minimum_greedy(nums);
    std::cout << "result-recur: " << result << std::endl;
    //#2

    nums = {2,3,0,1,4};
    result = jump_minimum_greedy(nums);
    std::cout << "result-recur: " << result << std::endl;
    //#2

    return 0;
}
