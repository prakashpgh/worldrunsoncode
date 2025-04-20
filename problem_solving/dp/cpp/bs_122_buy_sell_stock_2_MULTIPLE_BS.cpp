/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

#include<vector>
#include<iostream>

int max_profit_multiple_tx(const std::vector<int>& prices) {
    int profit = 0;
    int n = prices.size();
    int buy = 0;
    int i = 0;
    while(i < n-1) {
        while(i < n-1 && prices[i] >= prices[i+1]) {
            i += 1;
        }
        buy = prices[i];

        while(i < n-1 && prices[i] <= prices[i+1]) {
            i += 1;
        }
        if(i < n && prices[i] > buy) {
            profit += prices[i] - buy;
        }
    }
    return profit;
}


int main() {
    std::vector<int> prices = {7,1,5,3,6,4};
    //Output: 7
    int profit = max_profit_multiple_tx(prices);
    std::cout << "result: " << profit << std::endl;

    prices = {1,2,3,4,5};
    //Output: 4
    profit = max_profit_multiple_tx(prices);
    std::cout << "result: " << profit << std::endl;

    prices = {7,6,4,3,1};
    //Output: 0}
    profit = max_profit_multiple_tx(prices);
    std::cout << "result: " << profit << std::endl;
}