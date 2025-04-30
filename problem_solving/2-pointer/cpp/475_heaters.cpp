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