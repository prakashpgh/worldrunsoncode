
def count_1s(num):
    count = 0
    while num:
        count += num & 1
        num >>= 1
    return count

#more efficient..
# O (number of 1s)
def count_1s_nmminus1(num):
    count = 0
    while num:
        num = num & num-1
        count += 1
    return count



input = 11
ones = count_1s(input)
print("ones:" + str(ones))
ones = count_1s_nmminus1(input)
print("ones:" + str(ones))
