/*
https://leetcode.com/problems/rotting-oranges/

use bfs
traverse the matrix, 
    find the fresh oranges, 
    q => fill with rotten 

    while q:
        ==> USE BFS FOr LEVEL ONLY SO YOU DONT GET THE ONCE THAT ARE MARKED ROTTEN, SO YOU COUNT THE MINUTES RIGHT
        add newly rotten to q
        reduce fresh count
        update the grid
        check fresh count == 0
    check fresh count
*/

#include<iostream>
#include<tuple>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<queue>
using namespace std;


int rotten_oranges(std::vector<std::vector<int>>& grid)  {
    int fresh = 0;
    std::queue<std::pair<int, int>> q;
    //find fresh ones, put the rottern in the q.
    for(int i = 0; i < grid.size(); ++i) {
        for(int j = 0; j < grid[0].size(); ++j) {
            if(grid[i][j] == 1) {
                fresh++;
            } else if(grid[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
    //std::cout << "fresh: " << fresh << std::endl;
    if(fresh==0) {
        return 0;
    }   

    int minutes = 0;
    ///go thru the rotten ones... rot the neighbors.
    std::vector<std::pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int rows = grid.size();
    int cols = 0;
    if(rows > 0) {
        cols = grid[0].size();
    }
    while(!q.empty())  {
        int len = q.size();
        //std::cout << "qq: " << q.size() << std::endl;
        //level order traverse to make sure only the oranges that were already rottern are only taken into account
        for(int i = 0; i < len; ++i) {
            auto pr = q.front();
            q.pop();
            for( auto dr : directions) {
                int r = pr.first + dr.first;
                int c = pr.second + dr.second;
                if(r >= 0 && r < rows && c >=0 && c < cols && grid[r][c] == 1)  {
                    grid[r][c] = 2;
                    q.push({r, c});
                    fresh--;
                    //std::cout << "fresh--: " << fresh << std::endl;
                }
            }
        }
        minutes++;
        //std::cout << "fresh: " << fresh << " minutes: " << minutes << std::endl;
        if(fresh == 0) {
            break;
        }
    }
    if(fresh == 0) {
        return minutes;
    } else {
        return -1;
    }
}


int main() {
    //#rotten_oranges
    std::vector<std::vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int minutes = rotten_oranges(grid);
    std::cout << "minutes: " << minutes << std::endl;
    #4
    
    
    grid = {{2,1,1},{0,1,1},{1,0,1}};
    minutes = rotten_oranges(grid);
    std::cout << "minutes: " << minutes << std::endl;
    //#-1
    
    
    grid = {{0,2}};
    minutes = rotten_oranges(grid);
    std::cout << "minutes: " << minutes << std::endl;
    #0
    return 0;    
}
