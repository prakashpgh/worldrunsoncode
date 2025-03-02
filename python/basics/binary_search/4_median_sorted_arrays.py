'''
https://leetcode.com/problems/median-of-two-sorted-arrays/

https://www.youtube.com/watch?v=q6IEA26hvXc

find m = l + (r-l)//2
                should run Binary search only one one of the arrasy... smaller one 
        find left partition of one A array
        find left partition of array-2  => half - len_B
        check partitions are correct
                rightmost_left_A < leftmost_right_B

        median = 
                min(left partitions)
                max(right partitions)


'''
def find_median_sorted_arrays(nums1:list[int], nums2:list[int]):
    A = nums1
    B = nums2
    total = len(nums1) + len(nums2)
    half = total //2
    #A should be the smaller array on which we run binary search.
    if len(B) < len(A):
        tmp = B
        B=A
        A=tmp

        #run binary search on A
    l = 0
    r = len(A)-1
    while True:
        i = l + (r-l) // 2  #A
        j = half - i - 2 #B 
        #i is mid point for A, j is mid point for B
        Aleft = A[i] if i >= 0 else float("-inf")
        Aright = A[i+1] if i+1< len(A) else float("inf")
        Bleft = B[j] if j >= 0 else float("-inf")
        Bright = B[j+1] if j+1< len(B) else float("inf")

        #check partitions are correct
        if Aleft <= Bright and Bleft < Aright:
            #odd => take the middle
            if total % 2: 
                return min(Aright, Bright)
            #even
            return (min(Aright, Bright) + max(Aleft, Bleft)) / 2 
        elif Aleft > Bright:
            r = i - 1
        else:
            l = i + 1


nums1 = [1,3]
nums2 = [2]
#Output: 2.00000
median = find_median_sorted_arrays(nums1, nums2)
print("median: " + str(median))


nums1 = [1,2]
nums2 = [3,4]
#Output: 2.50000
median = find_median_sorted_arrays(nums1, nums2)
print("median: " + str(median))



median = find_median_sorted_arrays(nums1, nums2)
print("median: " + str(median))

   



