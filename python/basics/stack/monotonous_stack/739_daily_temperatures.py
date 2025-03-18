#https://leetcode.com/problems/daily-temperatures/description/

#monotonous stack
#O(n)
#space O(n)
def daily_temperatures_stack(temperatures):
    result =[0]*len(temperatures)
    stk = []
    for i in range(0,len(temperatures)):
        while stk and temperatures[i] > stk[len(stk)-1][0]:
            (t, index) = stk.pop()
            result[index] = i - index
        stk.append((temperatures[i], i))
    return result


#O(n**n)
def daily_temperatures_bruteforce(temperatures):
    result =[0]*len(temperatures)
    for i in range(len(temperatures)):
        for j in range(i+1,len(temperatures)):
            if temperatures[i] < temperatures[j]:
                result[i] = j-i
                break
    return result


temperatures = [73,74,75,71,69,72,76,73]
result = daily_temperatures_bruteforce(temperatures)
print("result-1:" + str(result))

result = daily_temperatures_stack(temperatures)
print("result-2:" + str(result))


#Output: [1,1,4,2,1,1,0,0]

temperatures = [30,40,50,60]
result = daily_temperatures_bruteforce(temperatures)
print("result-1:" + str(result))

result = daily_temperatures_stack(temperatures)
print("result-2:" + str(result))


#Output: [1,1,1,0]

temperatures = [30,60,90]
result = daily_temperatures_bruteforce(temperatures)
print("result-1:" + str(result))

result = daily_temperatures_stack(temperatures)
print("result-2:" + str(result))

temperatures = [1,3,2,4]
result = daily_temperatures_stack(temperatures)
print("result-2:" + str(result))


#Output: [1,1,0]