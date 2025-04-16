
def longest_repeating_character_replacement(s:str, k:int) -> int:
    result = 0
    N = len(s)
    counts = [0] * 26
    l = 0
    longest = 0
    for r in range(N):
        counts[ord(s[r]) - 65] += 1

        while ((r-l+1) - max(counts) > k ):
            counts[ord(s[l]) - 65] -= 1
            l += 1
        longest = max(longest, r-l+1)
        
    return longest



input = "ABAB"
k = 2
#4
result = longest_repeating_character_replacement(input, k)
print("result: " + str(result))


