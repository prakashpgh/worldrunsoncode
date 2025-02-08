from tree_node import TreeNode

#          1
#    2           3
#4       5   10

A = TreeNode(1)
B = TreeNode(2)
C = TreeNode(3)
D = TreeNode(4)
E = TreeNode(5)
F = TreeNode(10)
A.left = B
A.right = C
B.left = D
B.right = E
C.left = F

print(A)

def pre_order(node : TreeNode):
    if node is None:
        return
    print(node)
    pre_order(node.left)
    pre_order(node.right)


def in_order(node : TreeNode):
    if node is None:
        return
    in_order(node.left)
    print(node)
    in_order(node.right)

def post_order(node : TreeNode):
    if node is None:
        return
    post_order(node.left)
    post_order(node.right)
    print(node)

def pre_order_iterative(node : TreeNode):
    stk = [node]
    while stk:
        popNode = stk.pop()
        print(popNode)
        if popNode.right:
            stk.append(popNode.right)
        if popNode.left:
            stk.append(popNode.left)


def in_order_iterative(node : TreeNode):
    stk = []
    curr = node
    while curr or stk:
        #get the leftmost of curr
        while curr:
            stk.append(curr)
            curr = curr.left
        #get from stack
        curr = stk.pop()
        print (curr)
        #point curr to right
        curr = curr.right


print("pre-order")
pre_order(A)

print("in-order")
in_order(A)

print("in_order_iterative")
in_order_iterative(A)


print("post-order")
post_order(A)

print("pre-order iterative")
pre_order_iterative(A)


#bfs - breadth first search using deque
from collections import deque

def bfs(node : TreeNode):
    q = deque()
    if node:
        q.append(node)
    while q:
        tempNode = q.popleft()
        print(tempNode)
        if tempNode.left:
            q.append(tempNode.left)        
        if tempNode.right:
            q.append(tempNode.right)        

print("bfs")
bfs(A)

print("search using dfs")
#search using dfs
def search(node : TreeNode, value):
    if not node:
        return None
    if node.val == value:
        return node
    foundNode = search(node.left, value)
    if not foundNode:
        foundNode = search(node.right, value)
    return foundNode

node = search(A, 8)
if node:
    print(node)

#search using Binary search tree BST
#          5   
#    1           8
#-1      3   7       9
print("search using BST")
A2=TreeNode(5)
B2=TreeNode(1)
C2=TreeNode(8)
D2=TreeNode(-1)
E2=TreeNode(3)
F2=TreeNode(7)
G2=TreeNode(9)

A2.left = B2
A2.right = C2
B2.left = D2
B2.right = E2
C2.left = F2
C2.right = G2

in_order(A2)

def search_bst(node : TreeNode, val):
    if not node:
        return None
    if node.val == val:
        return node
    elif val > node.val:
        return search_bst(node.right, val)
    elif val < node.val:
        return search_bst(node.left, val)

node = search_bst(A2, -2)
if node:
    print("found" + str(node))
else:
    print("not found")



