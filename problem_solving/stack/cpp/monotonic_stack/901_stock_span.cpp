/*
'''
https://leetcode.com/problems/online-stock-span/
monotonic decreasing stack..
store the price and the span
'''
*/
#include <stack>
#include <iostream>

class StockSpanner {
    private:
        std::stack<std::pair<int, int>> st;
    public:
        StockSpanner() {
        }
        
        int next(int price) {
            int span = 1;
            while(!st.empty() && st.top().first <= price) {
                span += st.top().second;
                st.pop();
            }
            st.push({price, span});            
            return span;            
        }
    };


int main() {
    StockSpanner stockSpanner;
    int result = stockSpanner.next(100);    
    std::cout << "result: " << result << std::endl;//1
    result = stockSpanner.next(80);    
    std::cout << "result: " << result << std::endl;//1
    result = stockSpanner.next(60);    
    std::cout << "result: " << result << std::endl;//1
    result = stockSpanner.next(70);    
    std::cout << "result: " << result << std::endl;//2
    result = stockSpanner.next(60);    
    std::cout << "result: " << result << std::endl;//1
    result = stockSpanner.next(75);    
    std::cout << "result: " << result << std::endl;//4
    result = stockSpanner.next(85);    
    std::cout << "result: " << result << std::endl;//6
}
