'''
insert into sorted array
'''

def insert_sorted_linear(nums, element):
    i = 0
    while i < len(nums) and element > nums[i]:
        i += 1
    nums.insert(i, element)
    return nums



def insert_sorted_binary(nums, element):
    l = 0
    r = len(nums)
    while l < r:
        m = l + (r-l)//2
        if nums[m] < element:
            l = m + 1
        else:
            r = m
    nums.insert(l, element)
    return nums




sorted_array = [1, 3, 5, 7, 9]
new_element = 6
result = insert_sorted_linear(sorted_array, new_element)
print("linear: " + str(result))

sorted_array = [1, 3, 5, 7, 9]
result = insert_sorted_binary(sorted_array, new_element)
print("binary: " + str(result))
