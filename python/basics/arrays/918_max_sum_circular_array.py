'''
https://leetcode.com/problems/maximum-sum-circular-subarray/

https://www.youtube.com/watch?v=vxer7ns7BIs

   max( specialsum, normalsum )
        special sum => when array is wrapped around
            rightMax array..
            suffix sum  => from end.
            
            prefixSum
            maxSum

            special sum = max(specialSum, prefixSum + rightMax[i + 1])

                maxSum => normal sum
            max(, specialSum)   
        


'''

def max_sum_circular_array():
    pass 