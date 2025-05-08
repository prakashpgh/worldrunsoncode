/*
'''
https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

sort by end-points => shooting at the end of the balloon is the best to reduce number of balloons required.
keep the arrow position at the end of the balloon.
if the start of next > end of previous, then arrow += 1
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


int minimum_number_of_arrows(const std::vector<int>& balloons) {
    int result = 0;
    return result;
}


int main() {
    std::vector<int> points;
    points = {{10,16},{2,8},{1,6},{7,12}};
    //#Output: 2
    //#Explanation: The balloons can be burst by 2 arrows:
    //#- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
    //#- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
    arrows = minimum_number_of_arrows(points)
    std::cout << "arrows: " << arrows << std::endl;
    
    
    points = {{1,2},{3,4},{5,6},{7,8}};
    //#Output: 4
    //#Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
    arrows = minimum_number_of_arrows(points);
    std::cout << "arrows: " << arrows << std::endl;
    
    
    points = {{1,2},{2,3},{3,4},{4,5}};
    //#Output: 2
    //#Explanation: The balloons can be burst by 2 arrows:
    arrows = minimum_number_of_arrows(points);
    std::cout << "arrows: " << arrows << std::endl;
}


