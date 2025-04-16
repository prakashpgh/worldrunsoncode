'''
https://leetcode.com/problems/construct-quad-tree/

QuadTree node
    isLeaf
    val
    topleft, topright
    bottomleft, bottomright

    
defining a quad tree: top left x1,y1 and length
    the node is always a square

    
same_val => checks if all the cells have the same value

recursive function {
    if all cells have same value, then the 4 nodes are None, and isLeaf=True, and val=1 or 0
    else
    call the function for all the 4 quadrants.
}
'''




class Node:
    def __init__(self, val, isLeaf, topLeft=None, topRight=None, bottomLeft=None, bottomRight=None):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight

    def __str__(self):
        val=(f"val: {int(self.val)}     isLeaf: {self.isLeaf}")
        return val


#check if all the values are same in the grid
def same_value(nums: list[list[int]], x1:int, y1:int, length:int) -> bool:
    for i in range(x1, x1+length):
        for j in range(y1,y1+length):
            if nums[i][j] != nums[x1][y1]:
                return False
    return True


def solve(grid:list[list[int]], x1:int, y1:int, length:int):
    if same_value(grid, x1, y1, length):
        return Node(grid[x1][y1], True)
    else:
        #recursive calls to the 4 
        root = Node(False, False)

        root.topLeft = solve(grid, x1,y1,length//2)
        root.topRight = solve(grid, x1, y1+length//2, length//2)
        root.bottomLeft = solve(grid, x1+length//22, y1, length//2)
        root.bottomRight = solve(grid, x1 + length//2, y1+length//2, length//2)
        return root

def construct(nums: list[list[int]]):
    return solve(nums, 0,0,len(nums))



grid = [[0,1],[1,0]]
#Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
node = construct(grid)
print(f"node: {str(node)}")



grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
#Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
node = construct(grid)
print(f"node: {str(node)}")
