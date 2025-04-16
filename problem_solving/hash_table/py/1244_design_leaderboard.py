'''
https://leetcode.com/problems/design-a-leaderboard/

t: N* O(log K)
s: O(K)
'''
from collections import defaultdict
import heapq

class Leaderboard:

    def __init__(self):
        self.scores = defaultdict(int)

    def addScore(self, playerId: int, score: int) -> None:
        self.scores[playerId] += score

    def top(self, K: int) -> int:
        #return sum(sorted(self.scores.values(), reverse=True)[:K])
        return sum(heapq.nlargest(K, self.scores.values()))


    def reset(self, playerId: int) -> None:
        self.scores[playerId] = 0


# Your Leaderboard object will be instantiated and called as such:
leaderboard = Leaderboard()
leaderboard.addScore(1, 73)  # leaderboard = {1: 73}
leaderboard.addScore(2, 56)  # leaderboard = {1: 73, 2: 56}
print(leaderboard.top(1))          # returns 73
leaderboard.reset(1)        # leaderboard = {1: 0, 2: 56}
leaderboard.addScore(2, 51) # leaderboard = {1: 0, 2: 107}
print(leaderboard.top(2))          # returns 107 (107 + 0)