

def sort_colors(input):
    counts = [0]*3
    for i in input:
        counts[i] += 1

    #print("counts: " + str(counts))
    j = 0
    for i in range(len(counts)):
        c = 0
        while c < counts[i]:
            input[j]=i
            j += 1
            c += 1
    print("input: " + str(input))




input = [2,0,2,1,1,0]
sort_colors(input)

input = [2,0,1]
sort_colors(input)