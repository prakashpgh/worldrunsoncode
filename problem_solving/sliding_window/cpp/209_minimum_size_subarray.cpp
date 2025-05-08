/*
#https://leetcode.com/problems/minimum-size-subarray-sum/description/
'''
t: O(n)
note that its sliding window..
'''
*/

int minimum_size_subarray_sum(int target, const std::vector<int>& nums) {
    int result = 0;
    return result;
}


//todo


int main() {
    int target = 7;
    std::vector<int> nums = {2,3,1,2,4,3};
    result = minimum_size_subarray_sum(target, nums);
    std::cout << "result: " << result << std::endl;
    //#Output: 2
    //#Explanation: The subarray [4,3] has the minimal length under the problem constraint.
        
    target = 4;
    nums = {1,4,4};
    result = minimum_size_subarray_sum(target, nums);
    std::cout << "result: " << result << std::endl;
    //#Output: 1
    
    target = 11;
    nums = {1,1,1,1,1,1,1,1};
    result = minimum_size_subarray_sum(target, nums);
    std::cout << "result: " << result << std::endl;
    //#Output: 0
}
