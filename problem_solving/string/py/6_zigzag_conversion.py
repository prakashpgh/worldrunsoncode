'''
https://leetcode.com/problems/zigzag-conversion/description/?envType=study-plan-v2&envId=top-interview-150

create a list of lists... like a matrix
    from the string, enter the words in to the matrix
    do a join    
'''

def zigzag_conversion(input:str, rows:int):
    output = []
    for i in range(rows):
        output.append([])
    r = 0
    down = True
    for s in input:
        output[r].append(s)
        if r == rows-1:
            down = False
        elif r==0:
            down = True
        if down:
            r = r+1
        else:
            r = r-1
    #print("output array :" + str(output))
    str_output = ""
    for row in output:
        str_output += "".join(row)
    return str_output



input = "PAYPALISHIRING"
rows = 3
output = zigzag_conversion(input, rows)
print("output: " + str(output))
#PAHNAPLSIIGYIR


rows = 4
output = zigzag_conversion(input, rows)
print("output: " + str(output))
#PINALSIGYAHRPI

input = "A"
rows = 1
#A
output = zigzag_conversion(input, rows)
print("output: " + str(output))




