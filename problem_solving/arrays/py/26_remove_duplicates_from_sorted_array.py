#https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#T O(n)
#S O(1)
def remove_duplicates_from_sorted_array(nums: list[int]) -> int:
    N=len(nums)
    if N <= 1:
        return len(nums)
    
    j = 1
    for i in range(1,N,1):
        if nums[i] != nums[i-1]:
            #found non-duplicate
            nums[j]=nums[i]
            j += 1
    return j





nums = [1,1,2]
result = remove_duplicates_from_sorted_array(nums)
print("result: " + str(result))
#utput: 2

nums = [0,0,1,1,1,2,2,3,3,4]
#Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
result = remove_duplicates_from_sorted_array(nums)
print("result: " + str(result))
