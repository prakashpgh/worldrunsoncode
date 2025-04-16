'''
735_asteroid_collision.py
#tricky

Idea
there can be collision only when the previous(top of stack) is +ve and new astroid is -ve.
1) no chance of collision when stack is empty, or new astroid is +ve or top is -ve
    in this case we add the new astroid to stack

2) Collision case
    a) if top and new are equal and opposite, then both explode, so u need to pop from stack.
    b) if top > -astroid, then astroid is destroyed, nothing to do.
    c) top is destroyed... pop().  if stack is empty, break the loop... else continue.
'''

def asteroid_collision(asteriods: list[int]):
    stack = []
    for ast in asteriods:
        while(True):
            #will never collide.
            if not stack or (ast > 0 or stack[-1] < 0):
                stack.append(ast)
                break
            else:
                if stack[-1] == -ast:  #equal case
                    stack.pop()
                    break
                elif stack[-1] > -ast:  #new astroid will be destroyed
                    break
                else:
                    stack.pop()
                    if not stack:
                        stack.append(ast)
                        break    
    return stack



asteroids = [5,10,-5]
#Output: [5,10]
result = asteroid_collision(asteroids)
print("result=" + str(result))

asteroids = [8,-8]
#Output: []
result = asteroid_collision(asteroids)
print("result=" + str(result))


asteroids = [10,2,-5]
#Output: [10]
result = asteroid_collision(asteroids)
print("result=" + str(result))
