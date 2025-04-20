/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=study-plan-v2&envId=top-interview-150

dp[i][j][1] = max*( dp[i-1][j][1] , dp[i-1][j-1][0] - price[i])

Not hodling         not holding     holding and then sole
dp[i][j][0]= max( dp[i-1][j][0] ,  dp[i-1][j][1] + price[i],  


*/

#include<vector>
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
/*
Holding
dp[i][j][1] = max*( dp[i-1][j][1] , dp[i-1][j-1][0] - price[i])

Not hodling         not holding     holding and then sole
dp[i][j][0]= max( dp[i-1][j][0] ,  dp[i-1][j][1] + price[i],  

 */
int max_profit_2_tx_dp(const std::vector<int>& prices) {
    int n = prices.size();
    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(3, std::vector<int>(2, 0)));
    

    dp[0][0][0] = 0;
    dp[0][1][0] = 0;
    dp[0][2][0] = 0;
    dp[0][1][1] = -prices[0];
    dp[0][2][1] = -prices[0];

    for (int i = 1; i < n; ++i) {
        for(int j = 1; j <= 2; ++j) {
            dp[i][0][0] = 0;
            dp[i][0][1] = INT_MIN;
            dp[i][j][0]= std::max( dp[i-1][j][0] ,  dp[i-1][j][1] + prices[i]);

            if (j > 0) {
                dp[i][j][1] = std::max( dp[i-1][j][1] , dp[i-1][j-1][0] - prices[i]);
                //std::cout << i << " => " <<  j <<  "=>" << dp[i][j][1] << std::endl;
            }
        }
    }
    return dp[n-1][2][0];
}



int max_profit_with_2_tx(const std::vector<int>& prices) {
    int buy_1 = INT_MAX;
    int profit_1 = INT_MIN;
    int eff_buy_2 = INT_MAX;
    int profit_2 = INT_MIN;
    for(auto price : prices ) {
        buy_1 = std::min(buy_1, price);
        profit_1 = std::max(profit_1, price - buy_1);
        eff_buy_2 = std::min(eff_buy_2, price-profit_1);
        profit_2 = std::max(profit_2, price - eff_buy_2);
    }
    return profit_2;
}


int main() {
    std::vector<int> prices = {3,3,5,0,0,3,1,4};
    //6
    int result = max_profit_with_2_tx(prices);
    std::cout << "result: " << result << std::endl;

    result = max_profit_2_tx_dp(prices);
    std::cout << "result: " << result << std::endl;
    return 0;
}

