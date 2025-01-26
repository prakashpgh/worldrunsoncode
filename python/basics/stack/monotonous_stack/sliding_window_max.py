'''
https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

https://www.youtube.com/watch?v=oaN9ibZKMpA


this leverages the histogram problem... which can be solved by using stacks..
    finding the minimum pre and post.
    then multiply the pre and post

    do this row by row pass the row to the histogram function
    .... for each row, calculate the area.
                        and find the max area
        for each row if there is 1, add it to the previous row... 
                    if there is zero, make the row element = 0

                        https://www.youtube.com/watch?v=oaN9ibZKMpA
                        
'''
