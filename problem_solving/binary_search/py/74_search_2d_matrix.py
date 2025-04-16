#https://leetcode.com/problems/search-a-2d-matrix/description/
#O(log (m * n))
'''
for binary search purposes, consider the matrix as a 1D array 0 to m*n-1
    when we want to find the element, r = m // cols,  c = m % cols
'''
def search_2d_matrix(matrix, target):
    m =len(matrix)
    n=len(matrix[0])
    t=m*n
    l = 0
    r = t-1
    while r >= l:
        m = l + (r-l)//2
        i = m//n
        j = m %n
        mid_num = matrix[i][j]
        if target == mid_num:
            return True
        elif target < mid_num:
            r = m-1
        else:
            l = m+1
    return False    






matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
target = 3
result = search_2d_matrix(matrix, target)
print("result: " + str(result))
#Output: true


matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
target = 13
result = search_2d_matrix(matrix, target)
print("result: " + str(result))
#Output: false