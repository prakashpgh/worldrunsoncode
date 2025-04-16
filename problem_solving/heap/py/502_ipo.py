'''
https://leetcode.com/problems/ipo/description/?envType=study-plan-v2&envId=top-interview-150

https://www.youtube.com/watch?v=1IUzNJ6TPEM

Idea..
All projects that have cost < w are put in the max-profit heap.

array => (c,p)min-heap => p max-heap

we have a limitation of the initial capital available.. so we need to rank projects by cost.
we use min-heap to get the project by lowest cost


we create a array of (c, p)
Heapify this by using min heap

note w never goes down.

for the k projects:
    while:
        get all the projects - for which the cost < w
        we pop all the projects which cost below available w, and put in the max-heap profit

    w += Now we pop out of this max heap
'''

import heapq
def ipo(k:int, w:int, profits: list[int], capital: list[int]):
    #get the combined array...
    combined = [(u,v) for u,v in zip(capital, profits)]
    heapq.heapify(combined)
    #min costs heap
    max_profits = []
    #for all the costs that are allowed, pop and fill the profits_max_heap ~ these are the allowed projects
    for i in range(k):
        while combined and combined[0][0] <= w:
            (c,p) = heapq.heappop(combined)
            heapq.heappush(max_profits, -p)
        if not max_profits:
            break
        w += -heapq.heappop(max_profits)                    
    return w



k = 2
w = 0
profits = [1,2,3]
capital = [0,1,1]
#Output: 4
result = ipo(k, w, profits, capital)
print("result: " + str(result))


k = 3
w = 0
profits = [1,2,3]
capital = [0,1,2]
#Output: 6
result = ipo(k, w, profits, capital)
print("result: " + str(result))
 