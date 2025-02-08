class Node:
    def __init__(self, key, value, prev=None, next = None):
        self._value = value
        self._key = key
        self._prev = prev
        self._next = next
        

class LRUCache:

    def __init__(self, capacity: int):
        self._capacity = capacity
        self._cache = {}
        self._head = None
        self._tail = None
        self._node_count = 0

    def get(self, key: int) -> int:
        if key in self._cache:
            self.remove_node(self._cache[key])
            self.add_node(self._cache[key])
            return self._cache[key]._value
        return -1

    def put(self, key: int, value: int) -> None:
        #check if it already exists.
        new_node = None
        if key in self._cache:
            new_node = self._cache[key]
            new_node._value = value
            self.remove_node(new_node)
            self.add_node(new_node)
        else:
            if self._node_count >= self._capacity:
                #evict from tail
                if self._tail:
                    tmp = self._tail
                    prev = self._tail._prev
                    if prev:
                        prev._next = None
                    self._tail = prev
                    if not self._tail:
                        self._head = None
                    if tmp._key in self._cache:
                        del self._cache[tmp._key]

                    tmp._next = None
                    tmp._prev = None
                    tmp = None
                    self._node_count -= 1

            new_node = Node(key, value)
            #add to cache
            self._cache[key] = new_node
            #update in the ll
            self.add_node(new_node)
            self._node_count += 1

    def add_node(self, new_node):
        if not self._head:
            self._head = new_node
            self._tail = new_node
            return
        else:
            new_node._next = self._head
            self._head._prev = new_node
            self._head = new_node
    
    def remove_node(self, node):
        prev = node._prev
        next = node._next
        node._next = None
        node._prev = None
        if node == self._tail and prev:
            prev._next = None
            self._tail = prev
        else:
            if prev:
                prev._next = next
            if next:
                next._prev = prev
        if node == self._head:
            self._head = next


    def traverse(self):
        nodes = []
        if self._head:
            node = self._head
            while node:
                nodes.append(str(node._value) + " => ")
                node = node._next
        return "".join(nodes)


# Your LRUCache object will be instantiated and called as such:

capacity = 1
obj = LRUCache(capacity)
print("6: " + str(obj.get(6)))
print("8: " + str(obj.get(8)))

obj.put(12,1)
print("2: " + str(obj.get(2)))
obj.put(15,11)
obj.put(5,2)
obj.put(1,15)
obj.put(4,2)
print("traverse: " + obj.traverse())
print("5: " + str(obj.get(5)))
obj.put(15,15)
print("traverse: " + obj.traverse())





'''
capacity = 5
obj = LRUCache(capacity)
param_1 = obj.get(5)
print("get: " + str(param_1))
obj.put(1,1)
obj.put(2,2)
obj.put(3,3)
obj.put(4,4)
obj.put(5,5)
print("traverse after adding 5: " + obj.traverse())
obj.put(6,6)
print("traverse after adding 6: " + obj.traverse())
obj.put(7,7)
print("traverse after adding 7: " + obj.traverse())
print("get: " + str(obj.get(3)))
print("afer get 3: " + obj.traverse())
print("get: " + str(obj.get(5)))
print("afer get 5: " + obj.traverse())

obj.put(8,8)
print("traverse after adding 8: " + obj.traverse())
obj.put(7,77)
print("traverse after adding 77: " + obj.traverse())
print("traverse: " + obj.traverse())
'''