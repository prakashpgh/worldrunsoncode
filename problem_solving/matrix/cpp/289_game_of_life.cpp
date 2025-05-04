/*
'''
https://leetcode.com/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150

we cannot change the matrix positions directly..
we need to change these to an intermediate number.

'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


void game_of_life(std::vector<std::vector<int>>& board) {

}



int main() {
    board = {{0,0,0},{1,0,1},{0,1,0}};
    print("board-before: " + str(board));
    game_of_life(board);
    print_vector(board);



    board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    print("board-before: " + str(board));
    #Output: {{0,0,0},[1,0,1],[0,1,1],{0,1,0}};
    game_of_life(board);
    print_vector(board);


    board = {{1,1},{1,0}};
    #Output: {{1,1},{1,1}};
    game_of_life(board);
    print_vector(board);
    return 0;
}