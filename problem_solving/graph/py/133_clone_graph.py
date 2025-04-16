
'''
https://leetcode.com/problems/clone-graph/description/?envType=study-plan-v2&envId=top-interview-150

1) dfs the orginal node, create the new graph... store the references from old to new in the hash map
2) iterate the hash_map, get the references from the old node, and create the references in the new node

dfs... when you pop from the stack, thats where you actually do the work

#meta #amazon
'''
#time: O(V+E)
#space: O(V)
from graph_node import Node

def clone_graph(node:Node)->Node:
    hash_map = {}

    def dfs(node):
        stack = []
        seen = set()
        clone = None
        if node:
            stack.append(node)
            seen.add(node)
            print(node)

        while stack:
            node_pop = stack.pop()
            #print(node_pop)
            hash_map[node_pop] = Node(node_pop.value)
            for nei in node_pop._neighbors:
                if nei not in seen:
                    stack.append(nei)
                    seen.add(node_pop)            
                    
        return hash_map[node]

    clone = dfs(node)
    for old_node, new_node in hash_map.items():
        for nei in old_node._neighbors:
            new_nei = hash_map[nei]
            new_node._neighbors.append(new_nei)
    return clone

A=Node(1)
B=Node(2)
C=Node(3)
D=Node(4)

A._neighbors.append(B)
A._neighbors.append(D)

B._neighbors.append(A)
B._neighbors.append(C)

C._neighbors.append(B)
C._neighbors.append(D)

D._neighbors.append(A)
D._neighbors.append(C)

A.display()
clone=clone_graph(A)

clone.display()

