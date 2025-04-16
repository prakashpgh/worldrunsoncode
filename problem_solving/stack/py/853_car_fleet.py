'''
https://leetcode.com/problems/car-fleet/description/

idea: 
    let c1 and c2 be cars.  C2, C1 => target.  C1 is nearer to the target than C2.
    If C1 reachese the target before C1.  then C1 is a disticnt fleet.
    If C2 reachese before or together with C1, then (C1 & C2) form a fleet.  the time is now that of C1.

        using time, if some car which is behind reaches first, make it part of the fleet
    sort by position.
    find the time required..
    iterate array..
        if time > slowest, then to fleet..
            update slowest

#meta
'''


def car_fleet(target:int, position:list[int], speed:list[int]):
    #sort the array by position
    cars = []
    for i in range(len(position)):
        cars.append((position[i], speed[i], (target-position[i])/speed[i]))
    print("input: " + str(cars))
    cars.sort(key=lambda x: x[0], reverse=True)
    print("sorted: " + str(cars))

    N = len(cars)
    timetoreach_slowest = (target - cars[0][0])/cars[0][1]
    fleet = 1
    for i in range(len(cars)):
        t1 = (target - cars[i][0])/cars[i][1]
        if t1 > timetoreach_slowest:
            fleet += 1
            timetoreach_slowest = t1

    return fleet


target = 12
position = [10,8,0,5,3]
speed = [2,4,1,1,3]
#3
result = car_fleet(target, position, speed)
print("car_fleet_1: " + str(result))




target = 10
position = [0,4,2]
speed = [2,1,3]
#1
result = car_fleet(target, position, speed)
print("car_fleet_1: " + str(result))





target = 10
position = [3]
speed = [3]
#Output: 1
result = car_fleet(target, position, speed)
print("car_fleet_1: " + str(result))


target = 100
position = [0,2,4]
speed = [4,2,1]
#Output: 1
result = car_fleet(target, position, speed)
print("car_fleet_1: " + str(result))
