'''
https://leetcode.com/problems/heaters/description/?envType=company&envId=bloomberg&favoriteSlug=bloomberg-thirty-days

sort houses and heaters
iterate the houses
    find the heater closest to the house..
    find the radius..
    find max_radius
'''

def heater_radius(houses: list[int], heaters:list[int]) -> int:
    houses.sort()
    heaters.sort()
    idxHeater = 0
    max_radius = 0
    for house in houses:
        while idxHeater+1 < len(heaters) and abs(heaters[idxHeater] - house) >= abs(heaters[idxHeater+1] - house):
            idxHeater += 1
        
        distance = abs(heaters[idxHeater] - house)
        max_radius = max(max_radius, distance)
    return max_radius



houses = [1,2,3]
heaters = [2]
result = heater_radius( houses, heaters )
print("result:" + str(result))


houses = [1,2,3,4]
heaters = [1,4]
result = heater_radius( houses, heaters )
print("result:" + str(result))


houses = [1,5]
heaters = [2]
result = heater_radius( houses, heaters )
print("result:" + str(result))
