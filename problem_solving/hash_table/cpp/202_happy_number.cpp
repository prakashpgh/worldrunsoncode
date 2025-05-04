/*
'''
https://leetcode.com/problems/happy-number/description/?envType=study-plan-v2&envId=top-interview-150

'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


bool is_happy_number(int n) {
    bool result = false;
    return result;
}


int main() {
    int n = 19;
    bool result = is_happy_number(n);
    std::cout << "result: " << result << std::endl;
    
    n = 2;
    result = is_happy_number(n);
    std::cout << "result: " << result << std::endl;
    return 0;
}
