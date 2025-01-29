
#time O(A+B)
#space: O(1)
def add(a, b):
    while b:
        carry = a ^ b  #without carry
        without_carry = (a & b) << 1
        a = carry
        b = without_carry
    return a

a = 7
b = 2
sum = add(a, b)
print("sum: " + str(sum))
