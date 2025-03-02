'''
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#meta
choices: 
    pairing with different letters mapped to a digit

exit:
    the length of the result == number of digits
'''

def phone_book_letter_combinations(input:str):
    sol = []
    result = []
    digit_map = {"2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs","8":"tuv", "9":"wzyz"}    
    n = len(input)

    def backtrack(i:int):
        if len(sol) == n or i == n:
            if len(sol) > 0:
                result.append("".join(sol))
            return
        ch = input[i]
        mapped_str = digit_map[ch]
        for c in mapped_str:
            sol.append(c)
            backtrack(i+1)
            sol.pop()
    backtrack(0)

    return result
    

digits = "23"
result = phone_book_letter_combinations(digits)
print("results: " + str(result))

digits = ""
result = phone_book_letter_combinations(digits)
print("results: " + str(result))

digits = "2"
result = phone_book_letter_combinations(digits)
print("results: " + str(result))
