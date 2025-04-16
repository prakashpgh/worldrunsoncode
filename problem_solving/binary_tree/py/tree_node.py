from collections import deque

class TreeNode:
    def __init__(self, val, left=None, right=None, parent = None):
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent

    def __str__(self):
        return str(self.val)


        


def bfs(node : TreeNode):
    q = deque()
    nodes = []
    if node:
        q.append(node)
    while q:
        tempNode = q.popleft()
        if not tempNode:
            nodes.append("None")    
            continue
        nodes.append(tempNode.__str__())
        if tempNode.left:
            q.append(tempNode.left)        
        else:
            q.append(None) 

        if tempNode.right:
            q.append(tempNode.right)        
        else:
            q.append(None) 
    return "[" + ",".join(nodes) + "]"
