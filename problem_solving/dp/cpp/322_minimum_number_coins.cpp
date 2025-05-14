/*
https://leetcode.com/problems/coin-change/
greedy approach does not always give the optimal solution

Approach I: recursive
            you need amount A
            recur(amount) {
            exit criteria

                    0 or -ve
            Choices:
                for() => coins {
                    min = min(min_needed, 1 + recur(amount-coin))
                }
            }
            Parameters: amount

    time ( S ^ n) => S is number of coin denominations, n = target amount
    space (n)

    with memoization
    (n * C)
        C = number of coin denominations

Approach II:
    find the coins needed for 0, 1 etc.. and build from there.

    dp array fill to float('inf')
    dp[0] = 0
        for for all dp[1] .. dp[target]
        for all coins {
            dp[i] = min(dp[i], dp[i-coin] + 1)
        }


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
