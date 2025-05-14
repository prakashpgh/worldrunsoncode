/*
https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii/

*/

#include<queue>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<tuple>
using namespace std;

typedef std::tuple<long long, int, int, int> State;

/*

*/
int minimum_time_to_reach(std::vector<std::vector<int>>& move_time) {
    int result = 0;
    int rows = move_time.size();
    int cols = 0;
    if(rows > 0) {
        cols = move_time[0].size();
    }
    if (rows == 1 && cols == 1) {
        return 0;
    }
    //r, c, parity
    //min heap
    std::priority_queue<State, vector<State>, std::greater<State>> pq;
    pq.emplace(0,0,0,0);

    std::vector<std::vector<std::vector<long long>>> visited(rows, std::vector<std::vector<long long>>(cols, std::vector<long long>(2, LLONG_MAX) ));
    
    std::vector<std::pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0} };

    while(!pq.empty()) {
        auto [time, r, c, priority] = pq.top();
        pq.pop();
        
        if(r == rows-1 && c == cols -1) {
            return static_cast<int>(time);
        }
        if(visited[r][c][priority] < time) {
            continue;
        } 

        visited[r][c][priority] = time;

        for( const auto direction : directions ) {
            int new_row = r + direction.first;
            int new_col = c + direction.second;

            if(new_row < 0 || new_row >= rows || new_col < 0 || new_col >= cols) {
                continue;
            }

            //even-odd-even
            int new_priority = (priority + 1) % 2;
            int move_cost = (priority + 1) % 2 + 1;
            long long new_time = std::max(time, static_cast<long long>(move_time[new_row][new_col])) + move_cost;
            if(visited[new_row][new_col][priority] > new_time ) {
                pq.emplace(new_time, new_row, new_col, new_priority);
            }
        }
     }
     return -1;
}


int main() {
    std::vector<std::vector<int>> moveTime = {{0,4},{4,4}};
    int result = minimum_time_to_reach(moveTime);
    std::cout << "result " << result << std::endl;
    return 0;
}