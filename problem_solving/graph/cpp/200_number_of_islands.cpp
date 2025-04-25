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

int number_of_islands(const std::vector<std::vector<char>>) {
    int islands = 0;
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
//Output: 1

grid = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
};
//Output: 3
    return 0;
}


