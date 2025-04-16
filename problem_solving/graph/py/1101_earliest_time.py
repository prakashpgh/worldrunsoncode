

def earliestAcq(connections: list[list[int]], N) -> int:
    prnt = {i:1 for i in range(N)}  #O(N)
    size = {i:0 for i in range(N)}   #O(N)
    connections.sort()  #n log(n)
    def find(x):
        if x == prnt[x]
            return x
        rootx = find(prnt[x])
        prnt[x]=rootx
        return rootx
    
    components = N
    #O(N)
    for t,u,v in connections:
        ru = find(u)
        rv = find(v)
        if ru != rv:
            if size(ru) < size(rv):
                prnt[ru] = rv
                size[rv] += size[ru]
            else:
                prnt[rv] = ru
                size[ru] += size[rv]
            components -= 1
            if components == 1:
                return t
    return -1
    
    