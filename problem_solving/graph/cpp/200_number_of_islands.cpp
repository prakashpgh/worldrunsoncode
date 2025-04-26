/*
https://leetcode.com/problems/number-of-islands/

iterate thru each element if its 1 and do a bfs on it.
bfs
    q.push(<std::pair<>>)
    while !q.empty {
        front
        pop

        bfs() on neighbors
    }
*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>

class Solution {
private:
    int rows = 0;
    int cols = 0;

    bool is_valid(int r, int c) {
        if(r >= 0 && r < rows && c >= 0 && c < cols) {
            return true;
        }
        return false;
    }

    const std::vector<std::vector<char>> n_indexes = {{0,-1},{-1,0},{0,1},{1,0}};
    void dfs(std::vector<std::vector<char>>& grid, int row, int col) {
        if(!is_valid(row, col)) {
            return;
        }
        
        for(int i = 0; i < n_indexes.size(); ++i) {
            int r = row + n_indexes[i][0];
            int c = col + n_indexes[i][1];
            if(!is_valid(r, c)) {
                continue;
            }
            if(grid[r][c] == '1') {
                grid[r][c] = '0';
                dfs(grid, r, c);
            }
        }
    }

public:
int number_of_islands(std::vector<std::vector<char>>& grid) {
    int islands = 0;
    rows = grid.size();
    if(rows) {
        cols = grid[0].size();
    }
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(grid[i][j] == '1') {
                grid[i][j] = '0';
                dfs(grid, i, j);
                islands += 1;
            }
        }
    }
    return islands;
}



};

int main() {
    std::vector<std::vector<char>> grid = {
  {'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}
};
  Solution solv;
  int islands = solv.number_of_islands(grid);
  std::cout << "islands: " << islands << std::endl;

//Output: 1

grid = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
};

//Output: 3
    islands = solv.number_of_islands(grid);
  std::cout << "islands: " << islands << std::endl;
    return 0;
}


