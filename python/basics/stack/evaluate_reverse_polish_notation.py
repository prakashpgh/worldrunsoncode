
from math import ceil, floor

def evaluate_reverse_polish_notation(tokens):
    stk = []
    operators = ["+","-","*", "/"]
    for token in tokens:
        if token not in operators:
            stk.append(int(token))
        else:
            if len(stk) < 2:
                return False
            op1 = stk.pop()
            op2 = stk.pop()
            if token == "+":
                stk.append(op2 + op1)
            elif token == "-":
                stk.append(op2 - op1)
            if token == "*":
                stk.append(op2 * op1)
            if token == "/":
                div = op2 / op1
                if div < 0:
                    stk.append(ceil(div))
                else:
                    stk.append(floor(div))

    return stk.pop()


tokens = ["2","1","+","3","*"]
result = evaluate_reverse_polish_notation(tokens)
print("result: " + str(result))
#9


tokens = ["4","13","5","/","+"]
result = evaluate_reverse_polish_notation(tokens)
print("result: " + str(result))
#6

tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
result = evaluate_reverse_polish_notation(tokens)
print("result: " + str(result))

#22
