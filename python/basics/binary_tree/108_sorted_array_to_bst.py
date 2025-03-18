'''
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
'''

from tree_node import TreeNode
from tree_node import bfs
from collections import deque

def convert_sorted_array_to_bst(nums: list[int]):
    def recur(l, r) -> TreeNode:
        if r < l:
            return None
        m = l + (r-l)//2
        #m = (l + r)//2
        node = TreeNode(nums[m])
        node.right = recur(m+1, r)
        node.left = recur(l, m-1)   #made a mistake here.. wrote m intead of m-1

        return node

    N=len(nums)
    root = recur(0, N-1)
    return root



nums = [-10,-3,0,5,9]
#Output: [0,-3,9,-10,null,5]
root = convert_sorted_array_to_bst(nums)
#print("root type: " + str(type(root)))
if root:
    print("result: " + str(root) )
    print("result: " + str(root) + " bfs: " + bfs(root))

nums = [1,3]
#Output: [3,1]