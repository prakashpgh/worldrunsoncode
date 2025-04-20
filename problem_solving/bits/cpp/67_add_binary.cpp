/*
https://leetcode.com/problems/add-binary/

traverse the strings from end..
    convert char to int.
    add & calc. carry
    convert back to result
*/
#include<iostream>
#include<string>
#include<algorithm>

std::string add_binary(const std::string& a, const std::string& b) {
    std::string result ="";
    int l1 = a.length();
    int l2 = b.length();
    int carry = 0;
    int i = l1-1;
    int j = l2-1;
    std::cout << "result-1: " << result << std::endl;
    while(i >= 0 || j >= 0 || carry != 0) {
        int sum = carry;
        if(i>=0) {
            sum += a[i--] - '0';
        }
        if(j>=0) {
            sum += b[j--] - '0';
        }
        carry = sum / 2;
        //sum = sum % 2;
        //std::cout << sum << std::endl;
        result += (sum % 2) + '0';
        std::cout << "result-2: " << result << std::endl;
    }
    std::cout << "result-3: " << result << std::endl;
    std::reverse(result.begin(), result.end());
    return result;
}


int main() {
    std::string a = "11";
    std::string b = "1";
    //Output: "100"
    std::string sum = add_binary(a, b);
    std::cout << "result: " << sum << std::endl;


    a = "1010";
    b = "1011";
    //Output: "10101"
    sum = add_binary(a, b);
    std::cout << "result: " << sum << std::endl;
    return 0;
}
