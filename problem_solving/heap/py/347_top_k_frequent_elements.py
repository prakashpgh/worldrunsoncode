'''
https://leetcode.com/problems/top-k-frequent-elements/description/

#meta
'''
import heapq

'''
put the frequency in a dictionary
heapify and put in an array..


space: O(n)
time: O(n log K)
'''
def top_k_frequent_elements(nums: list[int], k:int)->list[int]:
    hash = {}
    for n in nums:
        if n not in hash:
            hash[n] = 1
        else:
            hash[n] += 1
    nums_freq = []
    
    for key,value in hash.items():
        if len(nums_freq) < k:
            heapq.heappush(nums_freq, (value, key))        
        else:
            heapq.heappushpop(nums_freq, (value, key))        
    return [t[1] for t in nums_freq]


def top_k_frequent_elements_using_arrays(nums: list[int], k:int)->list[int]:
    N = len(nums)
    freq = [0] * (N+1)  #made mistake here used N
    hash = {}
    for n in nums:
        if n in hash:
            hash[n] += 1
        else:
            hash[n] = 1
    for key,value in hash.items():
        if freq[value] == 0:
            freq[value] = [key]
        else:
            freq[value].append(key)
    result = []
    for i in range(N, -1, -1):  #made mistake here... used N-1
        if freq[i] != 0:
            result.extend(freq[i])        
            if len(result) == k:
                break
    return result


nums = [1]
k = 1
#Output: [1]
result = top_k_frequent_elements(nums, k)
print("result: " + str(result))
result = top_k_frequent_elements_using_arrays(nums, k)
print("result-arrays: " + str(result))


nums = [1,1,1,2,2,3]
k = 2
#Output: [1,2]
result = top_k_frequent_elements(nums, k)
print("result: " + str(result))

result = top_k_frequent_elements_using_arrays(nums, k)
print("result-arrays: " + str(result))


