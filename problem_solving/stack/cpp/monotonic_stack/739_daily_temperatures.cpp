/*
#https://leetcode.com/problems/daily-temperatures/description/

#monotonous stack
#O(n)
#space O(n)
*/

#include "../../../../cpp/common_header.h"
#include "../../../../cpp/utils/utils.h"
#include<stack>


std::vector<int> daily_temperatures_stack(std::vector<int> input) {
    int len = input.size();
    std::vector<int> results(len, -1);
    std::stack<int> st;
    int index = 0;
    for(int i = len-1; i >= 0; --i) {
        while(!st.empty() && input[st.top()] <= input[i]) {
            st.pop();
        }
        if(!st.empty()) {
            results[i] = st.top()-i;
        }
        st.push(i);
    }
    return results;
}


int main() {
    std::vector<int> temperatures = {73,74,75,71,69,72,76,73};
    std::vector<int> result = daily_temperatures_stack(temperatures);
    print_vector(result);
    std::cout << "result done " << std::endl;
    //#Output: [1,1,4,2,1,1,0,0]

    temperatures = {30,40,50,60};
    result = daily_temperatures_stack(temperatures);
    print_vector(result);
    std::cout << "result done " << std::endl;
    //#Output: [1,1,1,0]

    temperatures = {30,60,90};
    result = daily_temperatures_stack(temperatures);
    print_vector(result);
    std::cout << "result done " << std::endl;
    //1,1,-1,

    temperatures = {1,3,2,4};
    result = daily_temperatures_stack(temperatures);
    print_vector(result);
    std::cout << "result done " << std::endl;
    //#Output: [1,2,1,-1]
}