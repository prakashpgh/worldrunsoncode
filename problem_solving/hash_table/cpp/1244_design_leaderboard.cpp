/*
https://leetcode.com/problems/design-a-leaderboard/

std::unordered<int, int> playerid_score_map
in top method, create a min heap..  if size() > K, pop()

unordered_map => 
*/

#include<queue>
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<stack>
#include<unordered_map>


class Leaderboard {
    private:
    std::unordered_map<int, int> scores_map;
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        scores_map[playerId] += score;
    }
    
    int top(int K) {
        int sum_k = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        for(const auto& [key, value] : scores_map) {
            heap.push(value);
            if(heap.size() > K) {
                heap.pop();
            }
        }
        while(!heap.empty()) {
            sum_k += heap.top();
            heap.pop();
        }
        return sum_k;
    }
    
    int top_players(int K) {
        int sum_k = 0;
        std::priority_queue< std::pair<int,int>, std::vector< std::pair<int,int> >, std::greater<std::pair<int,int>>> heap;
        for(const auto& pair : scores_map) {
            heap.push({pair.second, pair.first});
            if(heap.size() > K) {
                heap.pop();
            }
        }
        while(!heap.empty()) {
            const auto& pr = heap.top();
            sum_k += pr.first;
            int Id = pr.second;
            heap.pop();
        }
        return sum_k;
    }

    void reset(int playerId) {
        scores_map[playerId] = 0;
    }
};

int main() {
/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
    Leaderboard* obj = new Leaderboard();
    int playerId = 1;
    int score = 10;
    int K = 4;
    obj->addScore(playerId,score);
    int param_2 = obj->top(K);
    obj->reset(playerId);

}