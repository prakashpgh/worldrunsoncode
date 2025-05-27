
#xor with the same number gives zero
p = 25
result = p ^ p
print("result:" + str(result))


#right shift divides by 2
y = 28
result = y >> 1
print("result:" + str(result))


#left shift multiplies by 2
y = 28
result = y << 1
print("result:" + str(result))


#to obtain lsb, & 1
x = 5 & 1
print("x=" + str(bin(x))) 


#check number is even.
n = 24
is_even = (n & 1) == 0
print("is_even: " + str(is_even))


#check number is odd.
n = 21
is_odd = (n & 1) == 1
print("is_odd: " + str(is_odd))

#remove the rightmost 1
x = 5
x = x & (x-1)
print("x= " + str(x) + "  bin: " + bin(x))


#number of 1s in x = ones in [x & (x-1)] + 1
x=5
#ones_x = ones_x_x_1 + 1



#basic operations
#or |
#7
print("or: " + str(5 | 7))

#and    &
#5
print("and: " + str(5 & 7))

#xor 
# 2   
print("xor: " + str(5 ^ 7))


#~5  -6

#-----------------------conversion ---------------------------
#integer to binary
num = 5
bin1= bin(5)
print("binary:" + str(bin1))


#base 16
print( "hex:" + str(hex(17)))


dec1 = int(bin1, 2)
print("dec:" + str(dec1))

      






