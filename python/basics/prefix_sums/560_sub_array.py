'''
#https://leetcode.com/problems/subarray-sum-equals-k/description/
prefix_sum[right] - prefix_sum[left-1] = K

https://leetcode.com/problems/subarray-sum-equals-k/solutions/6381096/beats-95-python-code-intuition-approach-code-easy/?source=submission-ac
'''
def sub_array_sum(nums:list[int], k:int):
    summ=0
    has={0:1}
    count=0
    for i in range(len(nums)):
        summ+=nums[i]
        if summ-k in has:
            count+=has[summ-k]
        if summ in has:
            has[summ]+=1
        else:
            has[summ]=1
    return count    

'''
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
'''
    
nums = [1,-1,0]
k = 0
#Output: 3
result = sub_array_sum(nums, k)
print("result:k=" + str(k) + " => " + str(nums) + " => " + str(result))



nums = [1,1,1]
k = 2
#Output: 2
result = sub_array_sum(nums, k)
print("result:k=" + str(k) + " => " + str(nums) + " => " + str(result))

nums = [1,2,3]
k = 3
#Output: 2
result = sub_array_sum(nums, k)
print("result:k=" + str(k) + " => " + str(nums) + " => " + str(result))



nums=[1,2,3,-2,4]
#pref=[1,3,6,4,8]
k=5
result = sub_array_sum(nums, k)
print("result:k=" + str(k) + " => " + str(nums) + " => " + str(result))


nums = [1,1,1]
k = 2
#Output: 2
result = sub_array_sum(nums, k)
print("result:k=" + str(k) + " => " + str(nums) + " => " + str(result))


nums = [1,2,3]
k = 3
#Output: 2
result = sub_array_sum(nums, k)
print("result:k=" + str(k) + " => " + str(nums) + " => " + str(result))
