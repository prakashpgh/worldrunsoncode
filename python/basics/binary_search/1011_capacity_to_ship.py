'''
https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

Idea: apply binary search
    1) function to check days required to ship..with a given capacity...  keep adding weights till it exceeds capacity,, increase day count..
    2) start binary search .. with capacity of l = max_load(we need this min. capacity to ship this max load) end of r = total load.  
            m = l + (r-l) // 2
            if capacity does not work, increase l = m + 1
            if capacity works, r = mid
'''

def capacity_to_ship():
    pass






weights = [1,2,3,4,5,6,7,8,9,10]
days = 5
#Output: 15



weights = [3,2,2,4,1,4]
days = 3
#Output: 6



weights = [1,2,3,1,1]
days = 4
#Output: 3