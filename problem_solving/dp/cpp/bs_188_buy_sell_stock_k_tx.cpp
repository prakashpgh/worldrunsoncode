/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

3-dim vector .. days / tx / holding or not
                tx is from 0 to k, (k+1) array size
[i=days][j=transactions][holding=0|1]
HOLDING =>  (same as yesterday) Or (buy today)
//dp[i][j][1] = max( dp[i-1][j][1], (dp[i-1][j][0]) - prices[i])  )

NOT HOLDING => (same as yesterday) Or (sold today today)    => when we sell we consider it as a tx completed
//dp[i][j][0] = max( dp[i-1][j][0], dp[i-1][j-1][1]) + prices[i]  )
*/

#include<vector>
#include<iostream>

int max_profit(int k, const std::vector<int>& prices) {
    int n = prices.size();
    if(n <=1 || k == 0) {
        return 0;
    }

    // Handle large k
    if (k >= n / 2) {
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }

    //initialize the vector
    std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(k+1, std::vector<int>(2, 0) ));
    dp[0][0][0] = 0; // No transactions, not holdin
    for(int j = 0; j <= k; ++j) {
        //holding stock on day 0, for any number of tx, the net will be -price
        dp[0][j][1] = -prices[0];//holding on day 0
    }

    //note we are starting from i=1, i =0 is taken care of
    for(int i = 1; i < n;++i) {
        for(int j = 0; j <= k ; ++j) {
            //NOT HOLDING
            //dp[i][j][0] = dp[i-1][j][0];//do nothing
            //if (j > 0 && dp[i-1][j-1][1] != INT_MIN) {
            if (j > 0) {
                dp[i][j][0] = std::max( dp[i-1][j][0], dp[i-1][j-1][1] + prices[i]  );
            }
            //HOLDING
            dp[i][j][1] = std::max( dp[i-1][j][1], dp[i-1][j][0] - prices[i]  );
            //std::cout << i << "     " << j << "     " << dp[i][j][0] << "     " << dp[i][j][1] << "     "  << std::endl;
        }
    }
    return dp[n-1][k][0];
}

/*
space optimization
    Not holding: dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1] + prices[i]) (if j > 0).
    Holding: dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] - prices[i]).

    since i depends only on i-1, we dont need 3-dim array
*/
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

    //initialization
    std::vector<std::vector<int>> dp(k+1, std::vector<int>(2, 0) );
    dp[0][0] = 0;
    for(int j = 0; j <= k; ++j) {
        dp[j][1] = -prices[0];
    }

    for(int i = 1; i<n;++i) {
        for(int j=0; j <= k ;++j) {
            //NOT HOLDING
            int prev_not_holding = dp[j][0];//THIS IS THE OPTIMIZATION... VALUE FROM PREVIOUS DAY
            //dp[j][0] = dp[j][0]; // Do nothing => do we need this
            if (j > 0 && dp[j-1][1] != INT_MIN) {
                dp[j][0] = std::max( dp[j][0], dp[j-1][1] + prices[i]  );
            }

            //HOLDING
            if (prev_not_holding != INT_MIN) {
                dp[j][1] = std::max( dp[j][1], prev_not_holding - prices[i]  );
            }
            //std::cout << i << "     " << j << "     " << dp[i][j][0] << "     " << dp[i][j][1] << "     "  << std::endl;
            std::cout << "Day " << i << ", j=" << j << ": dp[" << j << "][0]=" << dp[j][0] << ", dp[" << j << "][1]=" << dp[j][1] << std::endl;
        }
    }
    std::cout << "Final dp[" << k << "][0] = " << dp[k][0] << std::endl;
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