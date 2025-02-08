

array = [1,2,3,4,5,6,7,8,9]
N=len(array)
prefix_sum=[0]*N
if len(array) > 0:
    prefix_sum[0]=array[0]

for i in range(1,N):
    prefix_sum[i] = prefix_sum[i-1]+array[i]

print("array: " + str(array))
print("prefix_sum: " + str(prefix_sum))