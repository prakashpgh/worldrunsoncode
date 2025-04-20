/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

[i=days][j=transactions][0|1]
HOLDING
dp[i][j][1] = max( dp[i-1][j][1], dp[i-1][j-1][0]) - prices[i]  )

NOT HOLDING
dp[i][j][0] = max( dp[i-1][j][1], dp[i-1][j][0]) + prices[i]  )
*/

#include<vector>
#include<iostream>

int max_profit(int k, const std::vector<int>& prices) {
    int n = prices.size();
    if(n <=1 || k == 0) {
        return 0;
    }

    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(k+1, std::vector<int>(2, 0) ));
    for(int j=1; j<=k; ++j) {
        dp[0][j][1] = -prices[0];
    }

    for(int i = 1; i<n;++i) {
        for(int j=1; j <= k ;++j) {
            //NOT HOLDING
            dp[i][j][0] = std::max( dp[i-1][j][0], dp[i-1][j][1] + prices[i]  );

            if(j > 0) {
                //HOLDING
                dp[i][j][1] = std::max( dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]  );
            }
            //std::cout << i << "     " << j << "     " << dp[i][j][0] << "     " << dp[i][j][1] << "     "  << std::endl;
        }
    }
    return dp[n-1][k][0];
}


int max_profit_space_optimization(int k, const std::vector<int>& prices) {
    int n = prices.size();
    if(n <=1 || k == 0) {
        return 0;
    }

    if (k >= n / 2) {
            int max_profit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    max_profit += prices[i] - prices[i - 1];
                }
            }
            return max_profit;
    }


    std::vector<std::vector<int>> dp(k+1, std::vector<int>(2, 0) );
    for(int j=1; j<=k; ++j) {
        dp[j][1] = -prices[0];
    }

    for(int i = 1; i<n;++i) {
        for(int j=1; j <= k ;++j) {
            //NOT HOLDING

            dp[j][0] = std::max( dp[j][0], dp[j][1] + prices[i]  );

            if(j > 0) {
                //HOLDING
                dp[j][1] = std::max( dp[j][1], dp[j-1][0] - prices[i]  );
            }
            //std::cout << i << "     " << j << "     " << dp[i][j][0] << "     " << dp[i][j][1] << "     "  << std::endl;
        }
    }
    return dp[k][0];
}



int main() {
    std::vector<int> prices = {2, 4, 1};
    int k = 2;
    int result = max_profit(k, prices);
    std::cout << "result: " << result << std::endl;
    //2
    result = max_profit_space_optimization(k, prices);
    std::cout << "result-optimization: " << result << std::endl;
    

    prices = {3, 2, 6, 5, 0, 3};
    k = 2;
    result = max_profit(k, prices);
    std::cout << "result: " << result << std::endl;
    //7
    result = max_profit_space_optimization(k, prices);
    std::cout << "result-optimization: " << result << std::endl;
    return 0;
}