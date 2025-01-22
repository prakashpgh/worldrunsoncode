
#time: O(n)
#space: O(1)
def nearest_to_zero(nums: list[int]):
    n = len(nums)
    nearest = nums[0]
    for i in range(n):
        if(abs(nums[i]) < abs(nearest)):
            nearest = nums[i]
    if(nearest < 0 and (abs(nearest) in nums)):
        nearest = -nearest
    return nearest

nums  = [-4,-2,1,4,8]
val = nearest_to_zero(nums)
print("nearest to zero: " + str(val))

