
def single_number(nums):
    num = 0
    for n in nums:
        num ^= n
    return num


nums = [2,2,1]
num = single_number(nums)
print("num: " + str(num))

nums = [4,1,2,1,2]
num = single_number(nums)
print("num: " + str(num))
