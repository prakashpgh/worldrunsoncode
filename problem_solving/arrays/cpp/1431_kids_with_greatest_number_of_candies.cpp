/*
'''
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

array problem
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;



std::vector<bool> kids_with_greatest_number_of_candies(std::vector<int>& candies, int extra_candies) {
    int len = candies.size();
    std::vector<bool> result(len, false);
    int m = 0;
    for(int i = 0; i < len; ++i) {
        //m = *std::max(candies.begin(), candies.end());
        if(candies[i] > m) {
            m = candies[i];
        }
    }
    std::cout << m << std::endl;
    for(int i = 0; i < len; ++i) {
        if(candies[i] + extra_candies >= m) {
            result[i] = true;
        }
    }
    return result;
}



int main() {
    std::vector<int> candies = {2,3,5,1,3};
    int extra_candies = 3;
    //Output: [true,true,true,false,true] 
    std::vector<bool> output = kids_with_greatest_number_of_candies(candies, extra_candies);
    return 0;
}
