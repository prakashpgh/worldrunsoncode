'''
https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections

note the cuts can be horizontal or vertical..

Horizontal cut:
    sort by r[1]
    prev_max_y = rects[0][3]
    iterate over the rectangles...

'''

def check_grid_canbe_cut_sections(n: int, rectangles: list[list[int]]) -> bool:
    if len(rectangles) < 3:
        return False
    
    #horizontal cuts
    def check_horizontal_cuts(): 
        rectangles.sort(key=lambda t:t[1])
        prev_y_max = rectangles[0][3]
        cuts = 0
        for i in range(len(rectangles)):
            starty = rectangles[i][1]
            endy = rectangles[i][3]
            if starty >= prev_y_max:
                cuts += 1
                if prev_y_max > n:
                    return False
                prev_y_max = endy
            else:
                prev_y_max = max(prev_y_max, endy)
        return cuts == 2
    
    def check_vertical_cuts(): 
        rectangles.sort(key=lambda t:t[0])
        prev_x_max = rectangles[0][2]
        cuts = 0
        for i in range(len(rectangles)):
            startx = rectangles[i][0]
            endx = rectangles[i][2]
            if startx >= prev_x_max:
                cuts += 1
                if prev_x_max > n:
                    return False
                prev_x_max = endx
            else:
                prev_x_max = max(prev_x_max, endx)
        return cuts == 2

    return check_horizontal_cuts() or check_vertical_cuts()


n = 5
rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
result = check_grid_canbe_cut_sections(n, rectangles)
#true
print("result=" + str(result))


n = 4
rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]
result = check_grid_canbe_cut_sections(n, rectangles)
#true
print("result=" + str(result))



n = 4
rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]
#Output: false
result = check_grid_canbe_cut_sections(n, rectangles)
print("result=" + str(result))


n = 5
rectangles = [[0,0,1,2], [0,2,1,4], [0,4,1,5]]
result = check_grid_canbe_cut_sections(n, rectangles)
print("result=" + str(result))


n = 3
rectangles = [[0,0,1,1], [0,2,1,3], [2,0,3,1]]
result = check_grid_canbe_cut_sections(n, rectangles)
print("result=" + str(result))
