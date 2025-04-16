#https://leetcode.com/problems/count-good-nodes-in-binary-tree/

'''
bfs
    pass the max of the max( node_value, max_value ) to the nodes..
    check value and increment the count accordingly
    do a bfs... so you can put the node and the sum on the Q

MISTAKE understood the problem wrong initially
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque


def count_good_nodes_in_binary_tree(root: TreeNode):
    def bfs_traverse(node:TreeNode):
        if not node:
            return 0
        q = deque()
        count = 0
        hash = set()
        q.append((node, node.val))
        hash.add(node)

        while q:
            (q_node, largest) = q.popleft()
            if q_node.val >= largest:
                count += 1
            if q_node.left and q_node.left not in hash:
                q.append((q_node.left, max(largest, q_node.val)))
                hash.add(q_node.left)
            if q_node.right  and q_node.right not in hash:
                q.append((q_node.right, max(largest, q_node.val)))
                hash.add(q_node.right)
        return count
    return bfs_traverse(root)




#root = [3,1,4,3,None,1,5]
#Output: 4
#Explanation: Nodes in blue are good.
node_root = TreeNode(3)
node_root.left = TreeNode(1)
node_root.right = TreeNode(4)
node_root.left.left = TreeNode(3)
node_root.left.right = None
node_root.right.left = TreeNode(1)
node_root.right.right = TreeNode(5)
count = count_good_nodes_in_binary_tree(node_root)
print("count: " + str(count))



#root = [3,3,None,4,2]
#Output: 3
#Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
node_root = TreeNode(3)
node_root.left = TreeNode(3)
node_root.right = None
node_root.left.left = TreeNode(4)
node_root.left.right = TreeNode(2)
count = count_good_nodes_in_binary_tree(node_root)
print("count: " + str(count))


#root = [1]
#Output: 1
#Explanation: Root is considered as good.
node_root = TreeNode(3)
count = count_good_nodes_in_binary_tree(node_root)
print("count: " + str(count))
