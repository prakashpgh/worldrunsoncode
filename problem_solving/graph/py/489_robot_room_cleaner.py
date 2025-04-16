'''
https://leetcode.com/problems/robot-room-cleaner/description/

Idea:
    we dont have any info about the grid, we only have access to the robot api
    goback => go back to the previous square and maintain the direction

    solve by backtracking..parameters... x,y,direction
        use visited.
        clean()

        
        go in all four directions
            if not in visited and move() successful.
                backtrack(new x, new y, new direction)
                goback()

            turnright() #for the movement in other directions..



time: O(N-M)
space: O(N-M) N=all the tiles in the room, M= numbe of obstracles
'''

class Solution:
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        #up, right, down, left
        directions = [(-1,0), (0,1), (1,0), (0,-1)]
        visited = set()

        #go back... right, right, move, right, right
        def goback():
            #reverse
            robot.turnRight()
            robot.turnRight()
            robot.move()
            #back to the same direction
            robot.turnRight()
            robot.turnRight()

        def backtrack(x, y, direction):
            visited.add((x,y))
            robot.clean()

            for i in range(4):
                new_direction = (direction + i) % 4
                new_x = x + directions[new_direction][0]
                new_y = y + directions[new_direction][1]

                if (new_x,new_y) not in visited and robot.move():
                    backtrack(new_x, new_y, new_direction)
                    goback()

                robot.turnRight() #important

        backtrack(0,0,0)

