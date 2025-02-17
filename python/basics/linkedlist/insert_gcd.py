from linkedlist import ListNode


def gcd(a, b):
    mi = min(a, b)
    ma = max(a, b)
    remain = ma % mi
    while remain != 0:
        ma, mi = mi, remain
        remain = ma % mi
    return mi
        

def insert_gcd(input:ListNode):
    node = input
    prev = None
    while node:
        prev = node
        node = node._next
        if node and prev:
            gcd1 = gcd(prev._val, node._val)
            print("node: " + str(node) + " prev: " + str(prev) + " gcd: " + str(gcd1))
            gcd_node = ListNode(gcd1)
            gcd_node._next = node
            prev._next = gcd_node
    return input




A = ListNode(18)
B = ListNode(6)
C = ListNode(10)
D = ListNode(3)

A._next = B
B._next = C
C._next = D


result = gcd(12, 6)
print("gcd: " + str(result))

result = gcd(18, 12)
print("gcd: " + str(result))

result = gcd(12, 60)
print("gcd: " + str(result))


tr = A.traverse()
print("tr: " + tr)
n=2
result = insert_gcd(A)
print("after removing " + str(n) )
if result:
    tr = result.traverse()
    print("tr: " + tr)

