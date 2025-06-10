/*
https://leetcode.com/problems/koko-eating-bananas/'

binary search.
min. speed l = 1, max speed = max of the array.
Time taken for each pile => (p+m-1)/m  or std::ceil(static_cast<double>(p/m))
check if that speed is lower, => increase speed l = m+1
                    higher => reduce the speex r = m-1
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
#include<queue>
#include<math.h>

int koko_eating_bananas(const std::vector<int>& piles, int h)  {
    int l = 1;
    int r = *(std::max_element(piles.begin(), piles.end()));
    int m = 0;
    while(l < r) {
        m = l + (r-l)/2;
        long long time_taken = 0;
        for( int p : piles) {
            time_taken += (p+m-1)/m;
        }   
        if(time_taken > h) {
            l = m+1; 
        } else {
            //************* */
            r = m;
        }
    }
    return r;
}

int main() {
    std::vector<int> piles = {3,6,7,11};
    int h = 8;
    int result = koko_eating_bananas(piles, h);
    std::cout << "result: " << result << std::endl;
    
    piles = {30,11,23,4,20};
    h = 5;
    //#Output: 30
    result = koko_eating_bananas(piles, h);
    std::cout << "result: " << result << std::endl;
    
    
    piles = {30,11,23,4,20};
    h = 6;
    //#Output: 23
    result = koko_eating_bananas(piles, h);
    std::cout << "result: " << result << std::endl;
    
}
