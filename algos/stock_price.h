/**
 https://www.youtube.com/watch?v=1pkOgXD63yU&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=2* 
 
 input [7,1,5,3,6,4]

    2 pointer problem

buyIndex = lowest
    update if buy is lower

sellIndex = highest
    update when profit is highest

 */
 #include<vector>
 #include<iostream>

int find_profit(const std::vector<int> prices) {
    int buyIndex = 0;
    int maxProfit = 0;
    int sellIndex = 0;
    for(int i = 1; i < prices.size(); ++i) {
        int profit = prices[i] - prices[buyIndex];
        if( profit > maxProfit) {
            maxProfit = profit;
            sellIndex = i;
        }
        if( prices[i] < prices[buyIndex]) {
            buyIndex = i;
        }
    }
    
    std::cout << prices[buyIndex] << " ; " << prices[sellIndex] << " ; "  << maxProfit;
    return maxProfit;
}





 