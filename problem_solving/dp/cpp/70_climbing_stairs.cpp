/*
https://leetcode.com/problems/climbing-stairs/

Approch:
recursion

*/
#include<vector>
#include<unordered_map>
#include<iostream>

int recur(std::vector<int>& dp, int n) {
    if(n <= 1) {
        return 1;
    } 
    if(n == 2) {
        return 2;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] =recur(dp, n-1) + recur(dp,n-2);
    return dp[n];
}


int climbing_stairs_number_ways(int n) {
    std::vector<int> dp(n+1, -1);
    return recur(dp, n);
}


int main() {
    int n = 2;
    int result = climbing_stairs_number_ways(n);
    std::cout << "result: " << result << std::endl;

    n = 3;
    result = climbing_stairs_number_ways(n);
    std::cout << "result: " << result << std::endl;
}