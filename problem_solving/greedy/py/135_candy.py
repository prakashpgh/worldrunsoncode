'''
https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150
first pass: compare left to right. compare only the elements to its left
second pass: compare right to left.
'''

def candy(ratings: list[int]):
    N=len(ratings)
    candies = [1]*N
    total_candies=0
    if N > 0:
        candies[0] = 1
    for i in range(1,N):
        if ratings[i] > ratings[i-1]:
            candies[i]=candies[i-1]+1

    total_candies += candies[N-1]
    for i in range(N-2,-1,-1):          #mistake => the end index was kept to 0 instead of -1
        if ratings[i] > ratings[i+1] and candies[i] <= candies[i+1] :#made mistake here, did not have the candies condition
            candies[i] = candies[i+1]+1
        total_candies += candies[i]
    return total_candies


ratings = [1,3,4,5,2]
candies = candy(ratings)
print("candy: " + str(ratings) + " =   " + str(candies) )


ratings = [1,0,2]
#Output: 5
#Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
candies = candy(ratings)
print("candy: " + str(ratings) + " =   " + str(candies) )

ratings = [1,2,2]
#Output: 4
#Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
candies = candy(ratings)
print("candy: " + str(ratings) + " =   " + str(candies))










ratings = [1,0,2]
#Output: 5
#Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.


ratings = [1,2,2]
#Output: 4
#Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
#The third child gets 1 candy because it satisfies the above two conditions.

ratings = [5,4,3,5,6,2]
#12

ratings = [2,3,4,5]


