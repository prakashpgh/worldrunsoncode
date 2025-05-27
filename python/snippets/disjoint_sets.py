'''
https://leetcode.com/explore/featured/card/graph/618/disjoint-set/3878/
'''
#the array stores the ultimate root
#storage  O(N)
class QuickFind:
    def __init__(self, size):
        self.root = [i for i in range(size)]

    #O(1)
    def find(self, x):
        return self.root[x]
    
    #O(N)
    #iterate all and change the roots to the other
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            for i in range(len(self.root)):
                if self.root[i] == rootY:
                    self.root[i] = rootX

    #O(1)
    def connected(self, x, y):
        return self.find(x) == self.find(y)
    

uf = QuickFind(10)
# 1-2-5-6-7 
# 3-8-9 4
uf.union(1,2)
uf.union(2,5)
uf.union(5,6)
uf.union(6,7)

uf.union(3,8)
uf.union(8,9)

print("connected: 1, 5:  " + str(uf.connected(1,5)))
print("connected: 5, 7:  " + str(uf.connected(5,7)))
print("connected: 4, 9:  " + str(uf.connected(4,9)))
uf.union(9, 4)
print(uf.connected(4, 9))  # true


#
class QuickUnion:
    def __init__(self, size):
        self.root = [i for i in range(size)]

    #O(N)
    def find(self, x):
        while x != self.root[x]:
            x = self.root[x]
        return x
    
    #O(N)
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            self.root[rootY] = rootX
        
    def connected(self, x, y):
        return self.find(x) == self.find(y)
    


print("QuickUnion..")
uf = QuickUnion(10)
# 1-2-5-6-7 3-8-9 4
uf.union(1, 2)
uf.union(2, 5)
uf.union(5, 6)
uf.union(6, 7)
uf.union(3, 8)
uf.union(8, 9)
print(uf.connected(1, 5))  # true
print(uf.connected(5, 7))  # true
print(uf.connected(4, 9))  # false
# 1-2-5-6-7 3-8-9-4
uf.union(9, 4)
print(uf.connected(4, 9))  # true


#--UnionByRank

print("Unionbyrank...")
class UnionByrank:
    def __init__(self, size):
        self.root = [i for i in range(size)]
        self.rank = [1] * size 

    #O(log N)
    def find(self, x):
        if x == self.root[x]:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]

    #O(logN)
    def union(self, x, y):
        rootX = self.root[x]
        rootY = self.root[y]
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.root[rootY] = rootX
            elif self.rank[rootY] > self.rank[rootX]:
                self.root[rootX] = rootY
            else:
                self.root[rootY] = rootX
                self.rank[rootX] += 1

    #logN
    def connected(self, x, y):
        return self.find(x) == self.find(y)
    

# Test Case
uf = UnionByrank(10)
# 1-2-5-6-7 
# 3-8-9 4
uf.union(1, 2)
uf.union(2, 5)
uf.union(5, 6)
uf.union(6, 7)

uf.union(3, 8)
uf.union(8, 9)

root_3 = uf.find(5)
root_3 = uf.find(5)

print(uf.connected(1, 5))  # true
print(uf.connected(5, 7))  # true
print(uf.connected(4, 9))  # false
# 1-2-5-6-7 3-8-9-4
uf.union(9, 4)
print(uf.connected(4, 9))  # true


#--------------------------------------
''''
this has everything...
UnionFind.. versionwhere the values are not the absolute roots.
    find() => using path optimization... once find(x) is called, all values of root[x] for all x in its set, are updated to the root.... O(logN)
    union() => using rank to have a balanced tree ....  O(logN)
'''
print("OptimizedUnionFindWithPathCompressionAndRank")
class OptimizedUnionFindWithPathCompressionAndRank:
    def __init__(self, size):
        self.root = [x for x in range(size)]
        self.rank = [1] * size
        pass

    def find(self, x):
        if x == self.root[x]:
            return x
        #path opitimization
        self.root[x] = self.find(self.root[x])
        return self.root[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.root[rootY] = rootX
            elif self.rank[rootY] > self.rank[rootX]:
                self.root[rootX] = rootY
            else:
                self.root[rootX] = rootY
                self.rank[rootX] += 1


    def connected(self, x, y):
        return self.find(x) == self.find(y)
        



# Test Case
uf = OptimizedUnionFindWithPathCompressionAndRank(10)
# 1-2-5-6-7 3-8-9 4
uf.union(1, 2)
uf.union(2, 5)
uf.union(5, 6)
uf.union(6, 7)
uf.union(3, 8)
uf.union(8, 9)
print(uf.connected(1, 5))  # true
print(uf.connected(5, 7))  # true
print(uf.connected(4, 9))  # false
# 1-2-5-6-7 3-8-9-4
uf.union(9, 4)
print(uf.connected(4, 9))  # true