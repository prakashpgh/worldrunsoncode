'''
https://leetcode.com/problems/count-unhappy-friends/

#todo
'''


def count_unhappy_friends(n:int, preferences: list[list[int]], pairs: list[list[int]]) -> int:
    rank = [[0] * n for _ in range(n)]
    print(preferences)
    for i in range(n):
        for j, f in enumerate(preferences[i]):
            rank[i][f]=j
    print(rank)

    partner = [0]*n
    for x,y in pairs:
        partner[x]=y
        partner[y]=x
    print(partner)

    unhappy = set()
    for i in range(n):
        x = partner[i]
        if rank[i][x] > 0:
            unhappy.add(x)
    return len(unhappy)






n = 4
preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]]
pairs = [[0, 1], [2, 3]]
#Output: 2
result = count_unhappy_friends(n, preferences,pairs)
print("result=" + str(result))

n = 2
preferences = [[1], [0]]
pairs = [[1, 0]]
#Output: 0
result = count_unhappy_friends(n, preferences,pairs)
print("result=" + str(result))



n = 4
preferences = [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]]
pairs = [[1, 3], [0, 2]]
#Output: 4
result = count_unhappy_friends(n, preferences,pairs)
print("result=" + str(result))
