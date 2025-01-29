'''
https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

                        
'''
def max_subarray(input: list[int], k:int):
    n = len(input)
    result = [0] * (n-k+1)
    
    for i in range(n-k+1):
        l = i 
        r = i + k -1
        max_item = 0
        for j in range(l,r):
            max_item = max(max_item, input[j])
        result[i] = max_item    
    return result




input = [1, 2, 3, 1, 4, 5]
k=3
result = max_subarray(input, k)
print("result: " + str(result))

