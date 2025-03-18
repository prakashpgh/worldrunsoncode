#bfs on binary tree..
from tree_node import TreeNode
from tree_node import bfs
from collections import deque

#binary tree balanced => number of leaves = N/2 + 1

#bfs - in level traversal..
    #gives all the nodes at a particular level
#t: O(N)
#s: O(N)
def bfs_binary_tree(root: TreeNode):
    q = deque()
    q.append(root)
    while q:
        l = len(q)
        for _ in range(l):
            node = q.popleft()
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)


#dfs
#t: O(N)  => travel each node once
#s: O(H)    => recursion.






#binary search tree
'''
recursive
iterative
search: t: O(logN)
        s: O(H)
'''

