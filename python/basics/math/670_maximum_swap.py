'''
https://leetcode.com/problems/maximum-swap/

Approach I: bruteforce O(n**2)

Approach II: 2 pass..  convert to a list, 
            I pass iterate r => l, fill the array with the max. number after that index
            II pass: iterate l => r, check if the no. in max_array is smaller, if yes, swap

Approach III: 
    number in form of string
    maintain an array of length 10.  .. to store the last seen index of these digits
    go thru our number, for each digit, check in 10-array from 9=>that digit +1, if anything good for swap
    if good, convert into list and do the swap 
'''

#O(n)   => 4 times
#space O(n)
def maximum_swap_two_pass(num: int) -> int:
    nums = list(str(num))
    N = len(nums)
    max_index = [0] * N
    max_index[N-1] = N-1
    for i in range(N-2, -1, -1):
        if nums[i] > nums[i+1]:
            max_index[i] = i
        else:
            max_index[i] = max_index[i+1]
    for i in range(N):
        if nums[i] < nums[max_index[i]]:
            tmp = nums[i]
            nums[i] = nums[max_index[i]]
            nums[max_index[i]] = tmp
            break
    return int("".join(nums))



def maximum_swap_digits(num: int) -> int:
    digits = [-1] * 10
    st = str(num)
    for i in range(len(st)):
        digits[int(st[i])] = i 
    print("digits:" + str(digits))

    for i in range(len(st)):
        for j in range(9, int(st[i])+1, -1):
            if int(st[i]) < j and digits[j] > i:
                st = list(st)
                tmp = st[i]
                st[i] = str(j)
                st[digits[j]] = tmp
                return int("".join(st))
    return num


num = 9973
#Output: 9973
result = maximum_swap_digits(num)
print("result using digits: " + str(result))

result = maximum_swap_two_pass(num)
print("result: " + str(result))



num = 2736
#Output: 7236
result = maximum_swap_digits(num)
print("result using digits: " + str(result))
result = maximum_swap_two_pass(num)
print("result: " + str(result))




