/*
https://leetcode.com/problems/coin-change/


*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<limits>
#include<map>
#include<unordered_map>

int solve(std::unordered_map<int, int>& dp, const std::vector<int>& coins, int amount) {
    if(amount == 0) {
        return 0;
    }
    if(amount < 0) {
        return std::numeric_limits<int>::max();
    }
    if(dp.find(amount) != dp.end() ) {
        return dp[amount];
    }
    int min = std::numeric_limits<int>::max();
    for (int coin : coins) {
        int r = solve(dp, coins, amount-coin);
        if (r != std::numeric_limits<int>::max()) {    //#revisit => if we dont use this line, it causes overflow
            min = std::min( min, 1 + r);
        }
    }
    dp[amount] = min;
    return min;
}

int min_coins(const std::vector<int>& coins, int amount) {
    std::unordered_map<int, int> dp;
    int req_coins = solve(dp, coins, amount);
    if(req_coins == std::numeric_limits<int>::max()) {
        return -1;
    }
    return req_coins;
}

#include<algorithm>
int main() {
    std::vector<int> coins = {1,2,5};
    std::sort(coins.begin(), coins.end(), std::greater<int>());
    int amount = 11;
    int result = min_coins(coins, amount);
    std::cout << "result: " << result << std::endl;
    return 0;
}
