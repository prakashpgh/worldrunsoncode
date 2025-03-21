'''
'''

def can_place_flowers(flowerbed: list[int], target) -> bool:
    len_flowers = len(flowerbed)
    count = 0
    for i in range(len_flowers):
        if flowerbed[i] == 1:
            continue
        left = (i-1 < 0 or flowerbed[i-1] == 0)
        right = i+1 > len_flowers-1 or flowerbed[i+1] == 0
        if right and left:
            flowerbed[i] = 1
            count += 1
        if count >= target:
            return True
    if count == target:
        return True
    return False


flowerbed = [1]
n = 0
#Output: true
result = can_place_flowers(flowerbed, n)
print("result=" + str(result))


flowerbed = [1,0,0,0,1]
n = 1
#Output: true
result = can_place_flowers(flowerbed, n)
print("result=" + str(result))


flowerbed = [1,0,0,0,1]
n = 2
#Output: false
result = can_place_flowers(flowerbed, n)
print("result=" + str(result))
