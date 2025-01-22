
#time: O(n)
#space: O(1)
def roman_to_int(roman: str) -> int:
    map = {"M":1000, "D":500, "C":100, "L":50, "X":10, "V":5,  "I": 1}
    n = len(roman)
    whole_number = 0
    i = 0
    while i < n:
        print("index:" + str(i))
        first = map[roman[i]]
        second = 0
        number = first
        if i+1 < n:
            second = map[roman[i+1]]
        if first < second:
            number = second - first
            i = i + 1
        print("number" + str(i) + " => " + str(number) )
        whole_number = whole_number + number
        i += 1

    return whole_number


roman ="MCMXCIV"
whole_number = roman_to_int(roman)
print("whole_number:" + str(whole_number))


