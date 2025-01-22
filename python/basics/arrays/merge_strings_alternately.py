

def merge_alternately(word1, word2):
    result = []
    nw1 = len(word1)
    nw2 = len(word2)
    index = 0
    while(index < nw1 and index < nw2):
        result += word1[index]
        result += word2[index]
        index += 1

    if index < nw1:
        for i in range(index, nw1, 1):
            result += word1[i]

    if index < nw2:
        for i in range(index, nw2, 1):
            result += word2[i]
    return ''.join([str(element) for element in result])


word1 = "abc"
word2 = "pqr"
output = merge_alternately(word1, word2)
print("output:" + str(output))


word1 = "ab"
word2 = "pqrs"
output = merge_alternately(word1, word2)
print("output 2:" + str(output))


word1 = "abcd"
word2 = "pq"
output = merge_alternately(word1, word2)
print("output 3:" + str(output))