/*
https://leetcode.com/problems/interleaving-string/description/?envType=study-plan-v2&envId=top-interview-150

https://www.youtube.com/watch?v=oRYUnwklC98

Approach I: recursion
    Choice: the char matches s1 & s3, s2 & s3
    if the character matches, then try the next character..
    try with both the strings if charactermatches.

    base case: sum of lengths, all indexes reach the lengths of the strings
        check for lengths - len(S1) + len(S2) 
*/
#include<string>
#include<iostream>
#include<tuple>
#include<map>
using namespace std;

class Solution {

public:
    int l1;
    int l2;
    int l3;
    std::string s1;
    std::string s2;
    std::string s3;
    std::map<std::tuple<int, int, int>, bool> memo;

    bool recur(int i, int j, int k) {
        if (memo.count({i, j, k})) {
            return memo[{i, j, k}];
        }

        if (i == l1 && j == l2 && k == l3) {
            return true;
        }

        bool ret1 = false;
        bool ret2 = false;

        if (i < l1 && s1[i] == s3[k]) {
            ret1 = recur(i + 1, j, k + 1);
        }

        if (j < l2 && s2[j] == s3[k]) {
            ret2 = recur(i, j + 1, k + 1);
        }

        memo[{i, j, k}] = ret1 || ret2;
        return memo[{i, j, k}];
    }

    bool is_interleave(const std::string s1, const std::string& s2, const std::string& s3) {
        l1 = s1.length();
        l2 = s2.length();
        l3 = s3.length();

        if (l1 + l2 != l3) {
            return false;
        }

        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        memo.clear(); // Clear memoization for each call

        return recur(0, 0, 0);
    }
};


int main() {
    Solution solv;
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbbaccc";
    bool result = solv.is_interleave(s1, s2, s3);
    std::cout << "result: " << result << std::endl;
    //false
    
    s1="aabcc";
    s2="dbbca";
    s3="aadbbcbcac";
    result = solv.is_interleave(s1, s2, s3);
    std::cout << "result: " << result << std::endl;
    //true

    s1 = "";
    s2 = "";
    s3 = "";
    result = solv.is_interleave(s1, s2, s3);
    std::cout << "result: " << result << std::endl;
    //true
}
