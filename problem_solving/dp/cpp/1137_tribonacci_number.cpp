/*
'''
https://leetcode.com/problems/n-th-tribonacci-number
similar to fibonacii..
t: O(N)
s: O(1)
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
#include<math.h>


int tri_bonacci(int n)  {
    if(n==0) {
        return 0;
    }
    if(n <= 2) {
        return 1;
    }
    int result = 0;
    int t0 = 0;
    int t1=1;
    int t2=1;
    for(int i = 3; i <= n; ++i) {
        result = t0 + t1 + t2;
        t0 = t1;
        t1= t2;
        t2= result;
    }
    return result;
}


int main() {
    int n = 4;
    //#Output: 4
    int result = tri_bonacci(n);
    std::cout << "result: " << result << std::endl;
    
    n = 25;
    //#Output: 1389537
    result = tri_bonacci(n);
    std::cout << "result: " << result << std::endl;
    
}
