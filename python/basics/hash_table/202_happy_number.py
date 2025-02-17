'''
https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150

'''

def is_happy_number(n:int) -> bool:
    def digits(n):
        digi = []
        while n != 0:
            r = n % 10
            digi.append(r)
            n = n//10
        return digi

    repeat_check = set()
    while True:
        #print("n=" + str(n))
        #get digits
        digi = digits(n)
        sum = 0
        for d in digi:
            sum += d * d
        
        if sum == 1:
            return True

        #check for repetition
        if sum in repeat_check:
            return False
        repeat_check.add(sum)
        n = sum


n = 19
result = is_happy_number(n)
print("result: " + str(result))


n = 2
result = is_happy_number(n)
print("result: " + str(result))