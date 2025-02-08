'''
https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150

gain for each station..
if the total gain > 0, its possible, 
for each station 
    if current gain goes -ve, then that station is surely not possible, lets try the next one & make current_gain = 0

'''

def can_complet_circuit(gas:list[int], cost:list[int]) -> bool:
    ngas = len(gas)
    total_gain = 0
    station = 0
    curr_gain = 0
    for i in range(ngas):
        net = gas[i] - cost[i]
        total_gain += net
        curr_gain += net

        if curr_gain < 0:
            #try next station
            station = i+1
            curr_gain = 0
    if total_gain >= 0:
        return station
    return -1


gas = [1,2,3,4,5]
cost = [3,4,5,1,2]
#Output: 3
ret = can_complet_circuit(gas, cost)
print("gas: " + str(gas) + " cost: " + str(cost) + " = " + str(ret))


gas = [2,3,4]
cost = [3,4,3]
#Output: -1
ret = can_complet_circuit(gas, cost)
print("gas: " + str(gas) + " cost: " + str(cost) + " = " + str(ret))
