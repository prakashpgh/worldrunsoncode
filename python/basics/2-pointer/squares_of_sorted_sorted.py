'''
squares of sorted array, also in sorted 
https://www.youtube.com/watch?v=syTs9_w-pwA&list=PLKYEe2WisBTFEr6laH5bR2J19j7sl5O8R&index=13
'''

def reverse_inplace(nums : list[int]):
    l =0
    r = len(nums)-1
    while l < r:
        if nums[l] > nums[r]:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1

def squares_of_sorted_array_sorted(num_array : list[int]) -> list[int]:
    l =0
    r = len(num_array)-1
    result=[]
    while l <= r:
        if abs(num_array[l]) >= abs(num_array[r]):
            result.append(num_array[l]*num_array[l])
            l += 1
        else:
            result.append(num_array[r]*num_array[r])
            r += -1
    reverse_inplace(result)
    return result

nums = [-4,-1,0,3,10]
result = squares_of_sorted_array_sorted(nums)
print("result: " + str(result))

nums = [-7,-3,2,3,11]
result = squares_of_sorted_array_sorted(nums)
print("result: " + str(result))
