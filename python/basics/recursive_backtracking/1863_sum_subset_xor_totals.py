'''
https://leetcode.com/problems/sum-of-all-subset-xor-totals/

'''
def xors(nums: list[list[int]]):
    sum = 0
    for i in range(len(nums)):
        result = 0
        for j in nums[i]:
            result ^= j
        sum += result
    return sum


def sum_subset_xor_totals(nums: list[int]) -> int:
    result = []
    
    def recur(index, ans):
        if index == len(nums):
            if ans:
                result.append(ans[:])
            return

        ans.append(nums[index])
        recur(index+1, ans)
        ans.pop()
        recur(index+1, ans)
        
    recur(0, [])
    print(result)
    return xors(result)



    

nums = [1,3]
#Output: 6
result = sum_subset_xor_totals(nums)
print("result:" + str(result))


nums = [5,1,6]
#Output: 28
result = sum_subset_xor_totals(nums)
print("result:" + str(result))


nums = [3,4,5,6,7,8]
#Output: 480
result = sum_subset_xor_totals(nums)
print("result:" + str(result))
