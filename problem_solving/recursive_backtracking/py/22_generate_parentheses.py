'''
https://leetcode.com/problems/generate-parentheses/
#we can have an ( bracket only if existing (  < n
#we can have a close if we have open( > )close
#base case: all brackets are used... n pairs

Choice: to select ( or )
            ) can be selected only when closing is less than opening
            append, backtrack, pop

exit criteria: 
    check len, number of ( and )
'''
def generate_parentheses(n:int)->list[str]:
    sol = []
    result = []
    OPEN_BACKET="("
    CLOSE_BACKET=")"

    def backtrack():
        if len(sol) == n*2 and sol.count(OPEN_BACKET) == n and sol.count(CLOSE_BACKET) == n:
            result.append("".join(sol))
            return
        
        #add open
        if sol.count(OPEN_BACKET) < n:
            sol.append(OPEN_BACKET)
            #print("open added " + str(sol))
            backtrack()
            sol.pop()

        if sol.count(OPEN_BACKET) > sol.count(CLOSE_BACKET):
            #print("close added " + str(sol))
            sol.append(CLOSE_BACKET)
            backtrack()
            sol.pop()

    backtrack()
    return result



input = 3
#["((()))","(()())","(())()","()(())","()()()"]
result = generate_parentheses(input)
print("result 1: " + str(result))

input = 1
result = generate_parentheses(input)
print("result 2: " + str(result))
#["()"]

