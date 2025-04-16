'''
https://leetcode.com/problems/dot-product-of-two-sparse-vectors

Approach I: brute force
    O(n)
    O(1)
    
Approach II: using hash table
        store non-zeros in hash table O(n)
        dot products of hash table O(L)
    time: O(n) for hash table, O(L) for calculating dot product
    space: O(L)
Approach III
    
'''


class SparseVector:
    def __init__(self, nums: list[int]):
        self.nums = nums

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        result = 0
        N = len(self.nums)
        for n in range(N):
            if self.nums[n] and vec.nums[n]:
                result += self.nums[n] * vec.nums[n]
        return result





class SparseVector_hashtable:
    def __init__(self, nums: list[int]):
        self.dict = {}
        N = len(nums)
        for i in range(N):
            if nums[i]:
                self.dict[i] = nums[i]

    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        result = 0
        for index,v in self.dict.items():
            if index in vec.dict:
                result += v * vec.dict[index]
        return result



nums1 = [1,0,0,2,3]
nums2 = [0,3,0,4,0]
#Output: 8
a = SparseVector_hashtable(nums1)
b = SparseVector_hashtable(nums2)
result = a.dotProduct(b)
print("result: " + str(result))



nums1 = [0,1,0,0,0]
nums2 = [0,0,0,0,2]
#Output: 0
a = SparseVector_hashtable(nums1)
b = SparseVector_hashtable(nums2)
result = a.dotProduct(b)
print("result: " + str(result))


nums1 = [0,1,0,0,2,0,0]
nums2 = [1,0,0,0,3,0,4]
#Output: 6
a = SparseVector_hashtable(nums1)
b = SparseVector_hashtable(nums2)
result = a.dotProduct(b)
print("result: " + str(result))
