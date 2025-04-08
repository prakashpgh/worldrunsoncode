'''
https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

1) convert the tree into graph.... adjacency list
2) bfs => level order... each order ... 1 unit of time.
#todo
'''
from tree_node import TreeNode
from tree_node import bfs
from collections import deque

from collections import defaultdict

def amount_of_time_for_binary_tree_infected(root: TreeNode, start:int) -> int:
    graph = defaultdict(list)

    def build_tree(node):
        if not node:
            return
        if node.left:
            graph[node.val].append(node.left.val)
            graph[node.left.val].append(node.val)
            build_tree(node.left)
        if node.right:
            graph[node.val].append(node.right.val)
            graph[node.right.val].append(node.val)
            build_tree(node.right)
    
    build_tree(root)

    q = deque()
    q.append(start)
    time = -1 # start at -1 since minute 0 is the initial infection.
    visitor = set()
    visitor.add(start)
    while q:
        time += 1
        for _ in range(len(q)):
            item = q.popleft()
            for nei in graph[item]:
                if nei not in visitor:
                    q.append(nei)
                    visitor.add(nei)
    return time



node_root = TreeNode(2)
node_root.left = TreeNode(5)
result = amount_of_time_for_binary_tree_infected(node_root, 5)
print(result)