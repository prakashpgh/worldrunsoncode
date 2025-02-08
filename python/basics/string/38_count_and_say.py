import sys

def countAndSay(n):
    if n == 1:
        return "1"
    prev = countAndSay(n-1)
    N=len(prev)
    count = 1
    result = []
    for i in range(N):
        if i < N-1 and prev[i]!=prev[i+1]:
            result.append(str(count))
            result.append(prev[i])
            count = 1
        elif i < N-1 and prev[i] == prev[i+1]:
            count += 1
    result.append(str(count))
    result.append(prev[i])

    return "".join(result)

k = 1
st = countAndSay(k)
print("count_and_say: " + str(k) + "    "   + st)

k = 2
st = countAndSay(k)
print("count_and_say: " + str(k) + "    "   + st)

k = 3
st = countAndSay(k)
print("count_and_say: " + str(k) + "    "   + st)

k= 4
st = countAndSay(k)
print("count_and_say: " + str(k) + "    "   + st)

k = 5
st = countAndSay(k)
print("count_and_say: " + str(k) + "    "   + st)

k = 6
st = countAndSay(k)
print("count_and_say: " + str(k) + "    "   + st)


k = 7
st = countAndSay(k)
print("count_and_say: " + str(k) + "    "   + st)
