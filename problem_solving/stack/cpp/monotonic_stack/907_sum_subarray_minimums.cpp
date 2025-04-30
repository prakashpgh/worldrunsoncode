/* 
https://leetcode.com/problems/sum-of-subarray-minimums/

Approach I: one approach is to find all the sub arrays & find the min in each and sum up.

Approach II: for each element of array, find in how many subarrays they would appear as min element.
            sum += (element * count)

#difficult
 */

#include<iostream>
#include "../../../../cpp/common_header.h"
#include "../../../../cpp/utils/utils.h"
#include<stack>
using namespace std;


int sum_subarray_minimums(vector<int>& arr) {
    int len = arr.size();
    std::vector<int> prev(len, -1);
    std::vector<int> next(len, len);
    std::stack<int> st;
    //find the larger number to the left
    for(int i = 0; i < len; ++i) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            prev[i] = st.top();
        }
        st.push(i);
    }
    print_vector(prev);

    while(!st.empty()) {
        st.pop();
    }

    //find the smaller number to the right
    for(int i = len-1; i >= 0; --i) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            next[i] = st.top();
        }
        st.push(i);
    }
    print_vector(next);
    const int MOD = 1'000'000'007;
    //calc. sum
    int result = 0;
    for(int i = 0; i < len; ++i) {
        /*
        Left Range: (i - prevSmaller[i]) represents the number of possible starting indices for subarrays that include i and where arr[i] is the minimum.
        Right Range: (nextSmaller[i] - i) represents the number of possible ending indices for subarrays that include i and where arr[i] is the minimum.
        */
        long long count = (i - prev[i]) * (next[i] - i);
        result = (result + count * arr[i]) % MOD;
    }
    return result;
}


int main() {
    std::vector<int> arr = {3,1,2,4};
    int sum = sum_subarray_minimums(arr);
    std::cout << "result: " << sum << std::endl;
    return 0;
}