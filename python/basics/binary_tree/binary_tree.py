class TreeNode:
    def __init__(self, val, left=None, right=None):
        self._val = val
        self._left = left
        self._right = right

    def __str__(self):
        return str(self._val)

#          1
#    2           3
#4       5   10

A = TreeNode(1)
B = TreeNode(2)
C = TreeNode(3)
D = TreeNode(4)
E = TreeNode(5)
F = TreeNode(10)
A._left = B
A._right = C
B._left = D
B._right = E
C._left = F

print(A)

def pre_order(node : TreeNode):
    if node is None:
        return
    print(node)
    pre_order(node._left)
    pre_order(node._right)


def in_order(node : TreeNode):
    if node is None:
        return
    in_order(node._left)
    print(node)
    in_order(node._right)

def post_order(node : TreeNode):
    if node is None:
        return
    post_order(node._left)
    post_order(node._right)
    print(node)

def pre_order_iterative(node : TreeNode):
    stk = [node]
    while stk:
        popNode = stk.pop()
        print(popNode)
        if popNode._right:
            stk.append(popNode._right)
        if popNode._left:
            stk.append(popNode._left)

print("pre-order")
pre_order(A)

print("in-order")
in_order(A)

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
        if tempNode._left:
            q.append(tempNode._left)        
        if tempNode._right:
            q.append(tempNode._right)        

print("bfs")
bfs(A)

print("search using dfs")
#search using dfs
def search(node : TreeNode, value):
    if not node:
        return None
    if node._val == value:
        return node
    foundNode = search(node._left, value)
    if not foundNode:
        foundNode = search(node._right, value)
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

A2._left = B2
A2._right = C2
B2._left = D2
B2._right = E2
C2._left = F2
C2._right = G2

in_order(A2)

def search_bst(node : TreeNode, val):
    if not node:
        return None
    if node._val == val:
        return node
    elif val > node._val:
        return search_bst(node._right, val)
    elif val < node._val:
        return search_bst(node._left, val)

node = search_bst(A2, -2)
if node:
    print("found" + str(node))
else:
    print("not found")



