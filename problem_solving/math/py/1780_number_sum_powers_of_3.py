'''
https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
1780_number_sum_powers_of_3.py


keep dividing by 3...
if remainder is 2, then return false

#todo
'''



def number_sum_powers_of_3(n):
    while n:
        if n % 3 == 2:
            return False
        n = n // 3
    return True


