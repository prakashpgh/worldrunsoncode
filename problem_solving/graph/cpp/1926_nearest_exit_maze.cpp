/*
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
1926_maze_exit.py

classic BFS...
start with the entrance in the q.
level order =>to get the number of steps
    find the neighbours. add valid neighbours to the q
    exit when we find a corner cell
*/

#include<iostream>
#include<tuple>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<queue>
using namespace std;


int nearest_exit( std::vector<std::vector<char>>& maze, std::vector<int>& entrance)  {
    int steps = 0;
    std::queue<std::pair<int, int>> q;
    q.push({entrance[0], entrance[1]});
    std::vector<std::pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int rows = maze.size();
    int cols = 0;
    if(rows > 0) {
        cols = maze[0].size();
    }
    while(!q.empty())  {
        int level = q.size();
        for(int i = 0; i < level; ++i)  {
            auto ent = q.front();
            //maze[ent.first][ent.second] = '+';
            q.pop();
            int r = ent.first;
            int c = ent.second;
            if((r == 0 || r == rows-1 || c == 0 || c == cols-1 ) && !(r == entrance[0] && c == entrance[1]))  {
                return steps;
            }
            maze[r][c] = '+';
            for(auto dir : directions)  {
                r = ent.first + dir.first;
                c = ent.second + dir.second;
                //std::cout << r << ',' << c << std::endl;
                /*
                */
            /*
                if(r < 0 || r >= rows || c < 0 || c >= cols) {
                    continue;
                }
                if(maze[r][c] == '+') {
                    continue;
                }
              */  
                if(r >= 0 && r < rows && c >= 0 && c < cols && maze[r][c]=='.')   {
                    maze[r][c]='+';
                    q.push({r, c});
                }
                
            }
        }
        steps++;
    }
    return -1;
}


int main() {
    std::vector<std::vector<char>> maze = {{'.','+'}};
    std::vector<int> entrance = {0,0};
    //#Output: -1
    int result = nearest_exit(maze, entrance);
    std::cout << "result: " << result << std::endl; 
    
    
    maze = {{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    entrance = {1,0};
    //#Output: 2
    result = nearest_exit(maze, entrance);
    std::cout << "result: " << result << std::endl; 
    
    
    maze = {{'+','+','.','+'},{'.','.','.','+'},{'+','+','+','.'}};
    entrance = {1,2};
    //#Output: 1
    result = nearest_exit(maze, entrance);
    std::cout << "result: " << result << std::endl; 
    
}



