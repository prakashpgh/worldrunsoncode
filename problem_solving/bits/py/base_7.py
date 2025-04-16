
def to_base(num, base):
    result = []
    if num == 0:
        return "0"
    original_num = num
    num = abs(num)
    while num:
        result.append(str(num % base))
        num = num // base
    if original_num < 0:
        result.append("-")
    result.reverse()
    output = "".join(result)
    return output


result = to_base(100, 7)
print("result: " + str(result))


result = to_base(-100, 7)
print("result: " + str(result))
