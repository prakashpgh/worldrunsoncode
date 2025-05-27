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

#preorder

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Recursive Solution
def inorderTraversal_recursive(root):
    result = []
    
    def inorder(node):
        if not node:
            return
        inorder(node.left)    # Visit left subtree
        result.append(node.val)  # Visit current node
        inorder(node.right)   # Visit right subtree
    
    inorder(root)
    return result

# Iterative Solution
def inorderTraversal(root):
    result = []
    stack = []
    current = root
    
    while current or stack:
        # Reach the leftmost node
        while current:
            stack.append(current)
            current = current.left
        
        # Process current node
        current = stack.pop()
        result.append(current.val)
        
        # Move to right subtree
        current = current.right
    
    return result

# Example usage:
#     1
#      \
#       2
#      /
#     3
root = TreeNode(1)
root.right = TreeNode(2)
root.right.left = TreeNode(3)

print(inorderTraversal(root))  # Output: [1, 3, 2]



#post order


# Recursive Solution
def postorderTraversal_recursive(root):
    result = []
    
    def postorder(node):
        if not node:
            return
        postorder(node.left)    # Visit left subtree
        postorder(node.right)   # Visit right subtree
        result.append(node.val) # Visit current node
    
    postorder(root)
    return result

# Iterative Solution (using two stacks)
def postorderTraversal(root):
    if not root:
        return []
    
    result = []
    stack = [root]
    
    # First stack to process nodes, second to reverse order
    while stack:
        node = stack.pop()
        result.append(node.val)  # Add to result first (will be reversed)
        
        # Push left child first, then right
        # (so right will be processed before left in final result)
        if node.left:
            stack.append(node.left)
        if node.right:
            stack.append(node.right)
    
    return result[::-1]  # Reverse the result

# Example usage:
#     1
#      \
#       2
#      /
#     3
root = TreeNode(1)
root.right = TreeNode(2)
root.right.left = TreeNode(3)

print(postorderTraversal(root))  # Output: [3, 2, 1]





def preorder_traversal_recursive(root):
    """
    Recursive implementation of preorder traversal.

    Args:
        root: The root node of the binary tree.

    Returns:
        A list containing the preorder traversal of the tree.
    """
    result = []

    def preorder(node):
        if node:
            result.append(node.val)  # Visit the current node
            preorder(node.left)     # Traverse the left subtree
            preorder(node.right)    # Traverse the right subtree

    preorder(root)
    return result

def preorder_traversal_iterative(root):
    """
    Iterative implementation of preorder traversal.

    Args:
        root: The root node of the binary tree.

    Returns:
        A list containing the preorder traversal of the tree.
    """
    if not root:
        return []

    result = []
    stack = [root]

    while stack:
        node = stack.pop()
        result.append(node.val)

        # Push right child first, so left child is processed first.
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)

    return result

# Example usage:
# Constructing a sample binary tree
#        1
#       / \
#      2   3
#     / \
#    4   5

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

print("Recursive Preorder Traversal:", preorder_traversal_recursive(root))
print("Iterative Preorder Traversal:", preorder_traversal_iterative(root))