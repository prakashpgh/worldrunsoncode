/*
https://leetcode.com/problems/edit-distance/

https://www.geeksforgeeks.org/edit-distance-dp-5/
Approach I: recursive
    base: m ==0, return n, n ==0, return m => for insertions and deletions when one string ends

    start from end.. base case one of the string ends.

    if character match...  try with the strings with each index reduced by 1
    if character dont match => insert, replace, delete => get min.

    memoization: parameters m, n -lengths of the strings

Approach II: bottom up iterative
    create dp array with m+1, n+1 for 0-m
    fill case for when m = 0
    fill case for when n = 0

    iterate 1..m+1,n+1
        when string match ... no changes needed. so match [i-1][j-1]
        when dont match 1 + min(update, delete, insert)  1 is for 1char change
*/
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<tuple>
using namespace std;

class Solution {
    private:
    int l1;
    int l2;
    std::map<std::tuple<int, int>, int> memo;

    int recur(const std::string& word1, int i, const std::string& word2, int j) {
        if(i==0) {
            return j;
        }
        if(j == 0) {
            return i;
        }
        if(memo.count({i, j})) {
           return memo[{i,j}];
        }
        if (word1[i-1] == word2[j-1]) {
            memo[{i,j}] = recur(word1, i-1, word2, j-1);
        } else {
            int update = 1 + recur(word1, i-1, word2, j-1);
            int add = 1 + recur(word1, i, word2, j-1);
            int del = 1 + recur(word1, i-1, word2, j);
            memo[{i,j}] = std::min({update, add, del});
        }
        return memo[{i,j}];
    }

    public:
    int min_distance(const std::string& word1, const std::string& word2) {
        memo.clear();
        l1 = word1.length();
        l2 = word2.length();
        int ans = recur(word1, l1, word2, l2);
        return ans;
    }
};


int main() {
    std::string word1 = "horse";
    std::string word2 = "ros";
    //Output: 3
    Solution solv;
    auto result = solv.min_distance(word1, word2);
    std::cout << "result: " << result << std::endl;


    //case II
    word1 = "intention";
    word2 = "execution";
    //Output: 5
    result = solv.min_distance(word1, word2);
    std::cout << "result: " << result << std::endl;

    return 0;
}