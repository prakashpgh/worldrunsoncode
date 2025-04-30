/*
https://leetcode.com/problems/count-largest-group/
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;

int digit_sum(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int count_largest_group(int n) {
    std::unordered_map<int, int> map;
    int max_group_size = 0;
    for(int i = 1; i < n + 1; ++i ) {
        int sum = digit_sum(i);
        map[sum]++;
        max_group_size = std::max(max_group_size, map[sum]);
    }
    int count = 0;
    for(const auto& [n, size] : map) {
        if(max_group_size == size) {
            count += 1;
        }
    }
    return count;
}


int main() {
    cout << "countLargestGroup(13) = " << count_largest_group(13) << endl; // Output: 4
    cout << "countLargestGroup(2) = " << count_largest_group(2) << endl;  // Output: 2
    cout << "countLargestGroup(15) = " << count_largest_group(15) << endl; // Output: 6
    cout << "countLargestGroup(24) = " << count_largest_group(24) << endl; // Output: 5
    cout << "countLargestGroup(5000) = " << count_largest_group(5000) << endl;
    return 0;
}