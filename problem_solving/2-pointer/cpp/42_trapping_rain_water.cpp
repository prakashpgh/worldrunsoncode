/*
'''
https://leetcode.com/problems/trapping-rain-water/description/

Approach I:
max height to left
max height to right
min of [the max heights to right and left] - height of itself.  = water in that block....  
sum it up

Approach II:
    monotonous stack approach.

Approach III:
    2-pointer approach
    start pointers from both the ends..
    if l < r, move l, else move r => 
    keep tab of left_max and right_max
    if l > left_max, update left_max, no water can be stored here. same logic for r

'''
*/

#include<queue>
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<stack>


int trapping_rain_water_2pointer(const std::vector<int>& heights) {
    int l = 0;
    int r = heights.size() - 1;
    int l_max = 0;
    int r_max = 0;
    int total_water = 0;
    while(l < r) {
        if(heights[l] < heights[r]) {
            if(heights[l] > l_max) {
                l_max = heights[l];
            } else {
                total_water += l_max - heights[l];
            }
            l += 1;
        } else {
            if(heights[r] > r_max) {
                r_max = heights[r];
            } else {
                total_water += r_max - heights[r];
            }
            r -= 1;
        }
    }
    return total_water;
}




int main() {
    std::vector<int> height;
    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = trapping_rain_water_2pointer(height);
    std::cout << "result-2pointer: " << result << std::endl;
    //#Output: 6

    height = {4,2,0,3,2,5};
    //#Output: 9
    result = trapping_rain_water_2pointer(height);
    std::cout << "result-2pointer: " << result << std::endl;
    return 0;
}