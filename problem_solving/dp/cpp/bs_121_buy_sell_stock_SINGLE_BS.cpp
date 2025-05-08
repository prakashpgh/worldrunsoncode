/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

iterate the prices.  update the min. price.
for each tick,find the profit and update the max profit

t:  O(n)
s:  O(1)
*/

#include<vector>
#include<iostream>

int max_profit(const std::vector<int>& prices) {
    int buy = INT_MAX;
    int max_profit = INT_MIN;
    for(auto price : prices) {
        if(price < buy) {
            buy = price;
        }
        if(price > buy) {
            int profit = price - buy;
            max_profit = std::max(profit, max_profit);
        }
    }
    if(max_profit==INT_MIN) {
        max_profit = 0;
    }
    return max_profit;
}


int main() {
    std::vector<int> prices = {7,1,5,3,6,4};
    //Output: 5
    int profit = max_profit(prices);
    std::cout << "profit: " << profit << std::endl;

    prices = {7,6,4,3,1};
    profit = max_profit(prices);
    std::cout << "profit: " << profit << std::endl;
    //Output: 0
}