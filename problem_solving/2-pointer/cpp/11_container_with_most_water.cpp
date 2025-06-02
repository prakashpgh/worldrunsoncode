/*
#https://leetcode.com/problems/container-with-most-water/description/

#2-pointer - move the pointer with lesser height
#time O(n)
#space O(1)
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


int container_with_most_water(const std::vector<int> heights) {
    int water = 0;
    int l = 0;
    int r = heights.size()-1;
    int max_area = 0;
    while(l < r) {
        int area = ( std::min(heights[l], heights[r]) * (r-l) );
        if(area > max_area) {
            max_area = area;
        }
        if(heights[l] <= heights[r]) {
            l++;
        } else {
            r--;
        }
    }
    return max_area;
}


int main() {
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = container_with_most_water(height);
    std::cout << "result: " << result << std::endl;
    //#Output: 49

    //#Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


    height = {1,1};
    result = container_with_most_water(height);
    std::cout << "result: " << result << std::endl;
    //#output 1

}
