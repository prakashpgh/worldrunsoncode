'''
https://leetcode.com/problems/plus-one

start traversing from right..
if last digit is 9, make it 0
if last digit is not 9, just add +1 and return
    at end add 1 to array.. case of all 999
'''

def plus_one(input: list[int]) -> list[int]:
    N=len(input)
    for i in range(N):
        idx = N-1-i 
        if input[idx] == 9:
            input[idx] = 0
        else:
            input[idx] += 1
            return input
    return [1] + input





digits = [1,2,3]
#Output: [1,2,4]
output = plus_one(digits)
print("output: " + str(output))

digits = [4,3,2,1]
#Output: [4,3,2,2]
output = plus_one(digits)
print("output: " + str(output))

