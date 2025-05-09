/*

#https://leetcode.com/problems/subarray-sum-equals-k/description/
prefix_sum[right] - prefix_sum[left-1] = K

https://leetcode.com/problems/subarray-sum-equals-k/solutions/6381096/beats-95-python-code-intuition-approach-code-easy/?source=submission-ac

this is based on presum
    > presum has the sum of the array so far.
    check if 1) sum == K or sum-K in the hash map

def sub_array_sum(nums:list[int], k:int):
    N=len(nums)
    count = 0
    hash = {0:1} #this is needed if subarray starts from one
    prefix_sum = 0
    
    for i in range(N):
        prefix_sum += nums[i]
        #idea is if pre-sum for ith = presum of jth, then the sum of subarray from i to j = 0
        #similarly, if presum of ith = S-k, and presum of of jth is S, then the sum of subarray (i,j) is k
        if (prefix_sum-k) in hash:
            #result.append([hash[prefix_sums[i]-k]:nums[i+1]])
            count += 1
        freq = 0
        if prefix_sum in hash:
            freq = hash[prefix_sum]        
        hash[prefix_sum] = freq + 1
    return count

#interesting
*/
#include<vector>
#include<iostream>
#include<unordered_map>

int subarray_sum(const std::vector<int>& nums, int k) {
    int count = 0;
    std::unordered_map<int, int> map;
    map[0]=1;
    int sum = 0;
    for(int num : nums) {
        sum += num;
        if(map.find(sum-k) != map.end()) {
            count += map[sum-k];
        }
        map[sum] += 1;
    }
    return count;
}



int main() {
    std::vector<int> nums = {1,1,1};
    int k = 2;
    //Output: 2
    int result = subarray_sum(nums, k);
    std::cout << result << std::endl;

    nums = {1,2,3};
    k = 3;
    //Output: 2
    result = subarray_sum(nums, k);
    std::cout << result << std::endl;
}
