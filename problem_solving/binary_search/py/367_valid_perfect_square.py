#https://leetcode.com/problems/perfect-squares/
'''
    possible square roots 1 till N.
    use binary search
'''

def valid_perfect_square(N):
    l = 1
    r = N
    while l <= r:  #did mistake here <
        m = (l + r )//2
        sq = m * m
        if sq == N:
            return True
        elif sq < N:
            l = m + 1
        else:
            r = m -1
    return False


N=16
result = valid_perfect_square(N)
print("result: " + str(N) + " => " + str(result))


N=17
result = valid_perfect_square(N)
print("result: " + str(N) + " => " + str(result))


N=12
result = valid_perfect_square(N)
print("result: " + str(N) + " => " + str(result))
