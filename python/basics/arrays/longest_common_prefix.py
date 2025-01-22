#T(m * n) m = min. length
def longest_common_prefix(array: list[str]) -> str:
    if len(array) == 0:
        return ""
    prefix = ""
    prefix_list = []
    if len(array) > 0:
        min_len = len(array[0])
    for i in range(1, len(strs)):
        min_len = min(min_len, len(strs[i]))
    for i in range(0, min_len):
        ch = array[0][i]
        append = True
        for str in array:
            if str[i] != ch:
                append = False
                break
        if append:
            prefix_list.append(ch)
    return ''.join(prefix_list)


strs = ["flower", "flow", "flight"]
prefix = longest_common_prefix(strs)
print("prefix:" + prefix)

strs = ["dog", "racecar", "car"]
prefix = longest_common_prefix(strs)
print("prefix:" + prefix)

strs = ["flower", "flowz", "flow"]
prefix = longest_common_prefix(strs)
print("prefix:" + prefix)

strs = [""]
prefix = longest_common_prefix(strs)
print("prefix:" + prefix)
