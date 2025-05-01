/*
'''
https://leetcode.com/problems/heaters/description/?envType=company&envId=bloomberg&favoriteSlug=bloomberg-thirty-days

sort houses and heaters
iterate the houses
    find the heater closest to the house..
    find the radius..
    find max_radius
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>
#include<algorithm>


int heater_radius(std::vector<int>& houses, std::vector<int>& heaters) {
    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());
    int max_radius = 0;
    for(int house : houses) {
        int min_radius = INT_MAX;
        for(int heater : heaters) {
            min_radius = std::min( min_radius, abs(house - heater));
        }
        max_radius = std::max(max_radius, min_radius);
    }
    return max_radius;
}


//use of binary search
class Solution {
public:
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
        std::sort(heaters.begin(), heaters.end());
        int maxRadius = 0;
        
        for (int house : houses) {
            // Binary search to find the insertion point
            int left = 0, right = heaters.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (heaters[mid] < house) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            
            // Compute distances to closest heaters
            //#important...
            int leftDist = (left == 0) ? INT_MAX : house - heaters[left - 1];
            int rightDist = (left == heaters.size()) ? INT_MAX : heaters[left] - house;
            int minDist = std::min(leftDist, rightDist); 
            
            maxRadius = std::max(maxRadius, minDist);
        }
        
        return maxRadius;
    }
};


int main() {
    std::vector<int> houses;
    std::vector<int> heaters;
    houses = {1,2,3};
    heaters = {2};
    int result = heater_radius( houses, heaters );
    std::cout << "result:" << result << std::endl;


    houses = {1,2,3,4};
    heaters = {1,4};
    result = heater_radius( houses, heaters );
    std::cout << "result:" << result << std::endl;


    houses = {1,5};
    heaters = {2};
    result = heater_radius( houses, heaters );
    std::cout << "result:" << result << std::endl;
    return 0;
}