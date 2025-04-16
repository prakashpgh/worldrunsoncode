#sort on specific key
intervals = [[1,3],[9,6],[8,10],[15,18]]
print("before sort: " + str(intervals))
#intervals.sort(key=lambda t=t[0])
intervals.sort(key=lambda t:t[0])
print("after sort: " + str(intervals))

#sorting by 2 keys
intervals = [[1,3],[9,7],[9,6],[8,10],[15,18]]
print("before sort: " + str(intervals))
intervals.sort(key=lambda t:(t[0], t[1]))
print("after sort: " + str(intervals))



#frequency counter
freq_counter = [0]*26
s = "leetcode"
for c in s:
    freq_counter[ord(c)-ord('a')] += 1
print("freq_counter:" + str(freq_counter))



#math
s = "8"
i = ord(s) - ord('0')
print("i " + str(i))


#reversing arrays.
nums = [1,2,3,4,5,6,9,8]
nums.reverse()
print("nums: " + str(nums))

#reverse and stringfy
sort = "".join(str(x) for x in nums[::-1])
print("sort: " + str(sort))

###
#arrays..
nums = [1,2,3,4,5,6,7,8,9]
print(f"3rd index: {nums[3]}")



#-1 is the last, we get the results for N-1 for :N
nums = [1,2,3,4,5,6,7,8,9]
print(f"till :-2: {str(nums)} =>  {nums[:-2]}")


#slicing
nums = [1,2,3,4,5,6,7,8,9]
print(f":5 {str(nums)} => {nums[:5]}")


nums = [1,2,3,4,5,6,7,8,9]
print(f"3: {str(nums)} => {nums[3:]}")


nums = [1,2,3,4,5,6,7,8,9]
print(f"3:8 {str(nums)} => {nums[3:8]}")

nums = [1,2,3,4,5,6,7,8,9]
print(f"3:8:2 {str(nums)} => {nums[3:8:2]}")

nums = [1,2,3,4,5,6,7,8,9]
print(f"-3:-1 {str(nums)} => {nums[-3:-1]}")



#deep copy
nums = [1,2,3,4,5,6,7,8,9]
copy = nums[:-1]
copy[4]=100
print(f"deep copy: {str(nums)} => {str(copy)}")

#reversing - start is defaulted to 0, end is defaulted to end, step = -2
nums = [1,2,3,4,5,6,7,8,9]
print(f"reversing ::-2: {str(nums)} =>  {nums[::-2]}")


nums = [1,2,3,4,5,6,7,8,9]
print(f"reversing with -1:{str(nums)} =>  {nums[::-1]}")

#deep copy
import copy
dc = copy.deepcopy(nums)
print("deepcopy: " + str(dc))

#arrays and tuple
nums = [(1,11),(2,22),(3,33),(4,44),(5,55)]
tup = [t[1] for t in nums]
print("tup: " + str(tup))



###########################################################################
#zip
profits = [1,2,3,4,5,6,7,8,9]
capacity = [11,22,33,44,55,66,77,88,99]
combine = zip(profits, capacity)
print("zip: " + str(list(combine)))

##
#grids
offsets = [(0,-1),(-1,0),(0,1),(1,0)]
grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
#getting the neighbors
rows = len(grid)
cols = len(grid[0])
for r in range(rows):
    for c in range(cols):
        for off in offsets:
            i = r + off[0]
            j = c + off[1]


#fill 3d grid
m=3
n=4
memo = [[-1] * n for _ in range(m)]
print("memo: " + str(memo))