
'''
draw diagarm..
go thru the books, we have 2 options...
    try both options and find the min height

    1) same shelf - if book heigh 
    2) different shelf
    3) get min of the options 1 & 2
'''
def min_height_bookshelf(books, shelf_width):
    dp = {}

    def solve( i, remaining_width, max_height):
        if i >= len(books):
            return max_height
        if (i, remaining_width) in dp:
            return dp[(i, remaining_width)]

        book_width = books[i][0]
        book_height = books[i][1]
        same_shelf = float('inf')
        next_shelf = float('inf')
        if book_width <= remaining_width:
            #same shelf
            same_shelf = solve(i+1, remaining_width-book_width, max(max_height, book_height))

        next_shelf = max_height + solve(i+1, shelf_width-book_width, book_height)

        dp[(i, remaining_width)] = min(same_shelf, next_shelf)
        return min(same_shelf, next_shelf)

    result = solve(0, shelf_width, 0)
    return result


books = [[1,3],[2,4],[3,2]]
shelfWidth = 6
result = min_height_bookshelf(books, shelfWidth)


books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]
shelfWidth = 4
result = min_height_bookshelf(books, shelfWidth)
print("result: " + str(result))
#output: 6


books = [[1,3],[2,4],[3,2]]
shelfWidth = 6
result = min_height_bookshelf(books, shelfWidth)
print("result: " + str(result))

#Output: 4