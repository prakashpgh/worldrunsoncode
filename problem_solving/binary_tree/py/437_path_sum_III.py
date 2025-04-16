'''
https://leetcode.com/problems/path-sum-iii/

Idea:

'''

from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def path_sum_III(root: TreeNode, target_sum: int) -> int :
    count = 0
    prefix_sum = {0:1}
    def path_sum(node, curr_sum):
        nonlocal count
        if node == None:
            return

        curr_sum += node.val
        if (curr_sum - target_sum ) in prefix_sum:
            count += prefix_sum[curr_sum - target_sum]
        
        prefix_sum[curr_sum] = prefix_sum.get(curr_sum, 0 ) + 1

        path_sum(node.left, curr_sum)
        path_sum(node.right, curr_sum)

        prefix_sum[curr_sum] -= 1
        if prefix_sum[curr_sum] == 0:
            del prefix_sum[curr_sum]

    path_sum(root, 0)
    return count
