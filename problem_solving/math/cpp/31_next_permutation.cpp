/*
'''
https://leetcode.com/problems/next-permutation/

Intuition   1 3 5 2
 => from right, you need to get the first descending number 3 in 
        that is where you can possibly make a change.

    if i == -1, => everything is in the ascending order, the next sequence would be to reverse the digits.

    2) find smallest digit to the right that is greater than the pivot
        move from right => left
                    in above e.g its 5    
    3) swap nums[i] and nums[j]     1   5   3   2   => numbe becomes larger
    4) reverse after i =>   1   5   2   3   => reversing makes sure that we are getting the smallest number
////////////////////////////////////////////////////////
321
1) from right, find the first descending element i 
2) if i >= 0, find the smallest larger than [i]. .. this is j
3) swap [i] and [j]
4) reverse after i
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
#include<algorithm>
using namespace std;


void next_permutation(std::vector<int>& nums) {
    int len = nums.size();
    if(len <= 1) {
        return;
    }
    int i = len-2;
    while(i >= 0 && nums[i] >= nums[i+1]) {
        i -= 1;
    }     
    if(i < 0) {
        std::reverse(nums.begin(), nums.end());
        return;
    }
    int j = len-1;
    while(j > i && nums[j] <= nums[i]) {
        j -= 1;
    }
    //swap
    std::swap(nums[i], nums[j]);

    //reverse after i
    std::reverse(nums.begin() + i + i, nums.end());

}


int main() {
    std::vector<int> nums1 = {1, 2, 3};
    next_permutation(nums1);
    cout << "Next permutation of [1, 2, 3]: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl; // Output: 1 3 2

    vector<int> nums2 = {3, 2, 1};
    next_permutation(nums2);
    cout << "Next permutation of [3, 2, 1]: ";
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl; // Output: 1 2 3

    vector<int> nums3 = {1, 1, 5};
    next_permutation(nums3);
    cout << "Next permutation of [1, 1, 5]: ";
    for (int num : nums3) {
        cout << num << " ";
    }
    cout << endl; // Output: 1 5 1

    vector<int> nums4 = {1, 3, 5, 2};
    next_permutation(nums4);
    cout << "Next permutation of [1, 3, 5, 2]: ";
    for (int num : nums4) {
        cout << num << " ";
    }
    cout << endl; // Output: 1 5 2 3
}