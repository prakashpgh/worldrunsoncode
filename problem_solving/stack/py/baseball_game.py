#https://leetcode.com/problems/baseball-game/description/
def baseball_game(ops):
    stk = []
    for op in ops:
        if op == "C":
            stk.pop()
        elif op == "D":
            if len(stk) > 0:
                stk.append(2*stk[len(stk)-1])
        elif op == "+":
            if len(stk) > 1:
                stk.append(stk[len(stk)-1] + stk[len(stk)-2])    
        else:
            try:
                stk.append(int(op))                
            except:
                pass
    return sum(stk)    


ops = ["5","2","C","D","+"]
result = baseball_game(ops)
print("result: " + str(result))
output=30


ops = ["5","-2","4", "C","D","9", "+", "+"]
result = baseball_game(ops)
print("result: " + str(result))
#27