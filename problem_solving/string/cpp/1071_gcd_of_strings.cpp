/*
'''
https://leetcode.com/problems/greatest-common-divisor-of-strings/

1) check concat by order..
2) gcd of len of strings.

t:O(m+n) => compare string conat =>  O(m+n), 
            gcd (log (std::min(m, n)) ) 

s:O(m+n) => string comparison


Alternative approach:
    find the shorter string 
    iterate starting with short string len starting with full string {
        check if its gcd..
            gcdBase. the lengths should be multiples
            gcdBase*factor = original string
    }
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


int gcd(int m, int n) {
    int divisor = min(m,n);
    int dividend = max(m,n);
    int remain = 1;
    while (remain != 0 ) {
        remain = dividend % divisor;
        if (remain == 0)
            break;
        dividend = divisor;
        divisor = remain;
    }
        //#print("r: " + str(remain) + "r: " + str(divisor) + "r: " + str(dividend))
    return divisor;
}

std::string gcd_of_strings(std::string s1, std::string s2) {
    if (s1+s2 != s2+s1) {
        return "";
    }
    int max_length=gcd(s1.length(), s2.length());
    return s1.substr(0, max_length);
}
    


int main() {
    //int result = gcd(12, 16);
    //std::cout << "result= " << result << std::endl;
    
    
    std::string str1 = "ABCABC";
    std::string str2 = "ABC";
    //#Output: "ABC"
    std::string result = gcd_of_strings(str1, str2);
    std::cout << "result= " << result << std::endl;
    
    
    str1 = "ABABAB";
    str2 = "ABAB";
    //#Output: "AB";
    result = gcd_of_strings(str1, str2);
    std::cout << "result= " << result << std::endl;
    
    str1 = "LEET";
    str2 = "CODE";
    //#Output: "";
    result = gcd_of_strings(str1, str2);
    std::cout << "result= " << result << std::endl;
    
    return 0;
}
