/*
'''
https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150
first pass: compare left to right. compare only the elements to its left
second pass: compare right to left.
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


//#todo
int candy(const std::vector<int>& ratings)  {
    int candies = 0;
    return candies;
}




int main() {
    std::vector<int> ratings;
    ratings = {1,3,4,5,2};
    int candies = candy(ratings);
    std::cout << "candy: " << candies << std::endl;

    ratings = {1,0,2};
    //#Output: 5
    //#Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
    candies = candy(ratings);
    std::cout << "candy: " << candies << std::endl;

    ratings = {1,2,2};
    //#Output: 4
    //#Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
    candies = candy(ratings);
    std::cout << "candy: " << candies << std::endl;

    ratings = {1,0,2};
    //#Output: 5
    //#Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

    ratings = {1,2,2};
    //#Output: 4
    //#Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
    //#The third child gets 1 candy because it satisfies the above two conditions.

    ratings = {5,4,3,5,6,2};
    //#12

    ratings = {2,3,4,5};
}












