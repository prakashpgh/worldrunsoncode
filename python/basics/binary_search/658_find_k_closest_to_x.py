'''
https://leetcode.com/problems/find-k-closest-elements/
658_find_k_closest_to_x.py
'''

def find_k_closest_elements(arr: list[int], k:int, x:int) -> list[int]:
    l = 0
    r = len(arr) -1

    while l < r:
        m = l + (r-l)//2
        if m+k < len(arr) and (abs(x-arr[m]) > abs(arr[m+k]-x)):
            l = m+1
        else:
            r=m

    return arr[l:l+k]



print(find_k_closest_elements([1,2,3,4,5], 4, 3))         # [1,2,3,4]
print(find_k_closest_elements([1,2,3,4,5], 4, -1))        # [1,2,3,4]
print(find_k_closest_elements([1,1,1,10,10,10], 3, 9))    # [10,10,10]
print(find_k_closest_elements([1,3], 1, 2))               # [1]