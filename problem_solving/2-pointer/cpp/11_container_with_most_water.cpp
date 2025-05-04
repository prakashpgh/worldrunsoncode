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
    return water;
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
