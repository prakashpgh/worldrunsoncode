'''
https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-interview-150


'''

def product_of_array_except_self_bruteforce(nums: list[int])->list[int]:
    n = len(nums)
    result = [1]*n
    
    for i in range(n):
        for j in range(n):
            if i != j:
                result[i] = result[i] * nums[j]
    return result

#time: O(n)
#space: O(n)
'''
create pre and post list, multiply these
'''
def product_of_array_except_self(nums: list[int])->list[int]:
    n = len(nums)
    result = [0]*n
    pre = [0]*n
    pre[0]=1
    post = [0]*n
    post[n-1]=1
    
    for i in range(1,n):
        pre[i] = pre[i-1] * nums[i-1]
    print("pre: " + str(pre))
    for i in range(n-2,-1,-1):
        post[i] = post[i+1] * nums[i+1]
    print("post: " + str(post))

    for i in range(n):
        result[i]=pre[i] * post[i]
    return result

'''
only create the pre list
'''
def product_of_array_except_self_space(nums: list[int])->list[int]:
    n = len(nums)
    pre = [0]*n
    pre[0]=1
    
    for i in range(1,n):
        pre[i] = pre[i-1] * nums[i-1]
    print("pre: " + str(pre))
    mult = 1
    for i in range(n-1, -1, -1):
        pre[i]=pre[i] * mult
        mult = mult * nums[i]
    return pre


input = [1,2,3,4]
result = product_of_array_except_self(input)
print("result:" + str(result))

input = [-1,1,0,-3,3]
result = product_of_array_except_self(input)
print("result:" + str(result))


input = [1,2,3,4]
result = product_of_array_except_self_bruteforce(input)
print("result brute:" + str(result))

input = [-1,1,0,-3,3]
result = product_of_array_except_self_bruteforce(input)
print("result brute:" + str(result))


input = [1,2,3,4]
result = product_of_array_except_self_space(input)
print("result space:" + str(result))

input = [-1,1,0,-3,3]
result = product_of_array_except_self_space(input)
print("result space:" + str(result))
