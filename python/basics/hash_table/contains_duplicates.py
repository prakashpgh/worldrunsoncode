
def contains_duplicates(nums:list[int]):
    contains = False
    hash = set()
    for n in nums:
        if n in hash:
            return True
        else:
            hash.add(n)

    return False


nums = [1,2,3,1]
result = contains_duplicates(nums)
print("result: " + str(result))


nums = [1,2,3,4]
result = contains_duplicates(nums)
print("result: " + str(result))

nums = [1,1,1,3,3,4,3,2,4,2]
result = contains_duplicates(nums)
print("result: " + str(result))
