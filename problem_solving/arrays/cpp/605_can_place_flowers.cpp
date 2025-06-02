/*
https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75

*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


bool can_place_flowers(std::vector<int>& flowerbed, int n) {
    int len = flowerbed.size();
    int count = 0;
    if(n == 0) {
        return true;
    }
    for(int i = 0; i < len; ++i) {
        if(flowerbed[i] == 0 && 
            (i-1 < 0 || flowerbed[i-1]==0) && 
            (i+1 >= len || flowerbed[i+1]==0)) {
            flowerbed[i] = 1
            count++;
            if(count == n) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    std::vector<int> flowerbed = {1};
    int n = 0;
    //#Output: true
    bool result = can_place_flowers(flowerbed, n);
    std::cout << "result=" << result << std::endl;

    flowerbed = {1,0,0,0,1};
    n = 1;
    //#Output: true
    result = can_place_flowers(flowerbed, n);
    std::cout << "result=" << result << std::endl;


    flowerbed = {1,0,0,0,1};
    n = 2;
    //#Output: false
    result = can_place_flowers(flowerbed, n);
    std::cout << "result=" << result << std::endl;

    return 0;
}