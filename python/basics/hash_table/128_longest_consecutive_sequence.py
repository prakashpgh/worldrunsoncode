#Approach I: n log N => sort and then find the consecutive sequence
#check for the element which starts the sequence ... 
#O(n)
#space O(n)
def longest_consecutive_sequence(input:list[int]):
    hash_set = set(input)
    n = len(input)
    max_subseq_len=0
    for i in range(n):
        num=input[i-1]
        if num-1 not in hash_set:   #this is where the sequence starts... e.g 4,3,2... we start from 2. and go upwards
            subseq_len=1
            while num+1 in hash_set:
                subseq_len += 1
                num=num+1
            max_subseq_len = max(max_subseq_len, subseq_len)  

    return max_subseq_len




input = [100, 4, 200, 1,3,2]
result = longest_consecutive_sequence(input)
print("result=" + str(result))

input = [0,3,7,2,5,8,4,6,0,1]
result = longest_consecutive_sequence(input)
print("result=" + str(result))

