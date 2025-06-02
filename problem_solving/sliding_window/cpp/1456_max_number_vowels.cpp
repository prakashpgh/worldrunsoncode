/*'''
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<set>
#include<unordered_set>


int max_number_vowels(std::string s, int k) {
    int max_vowels = 0;
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    for(int i= 0; i < k; ++i) {
        if(vowels.find(s[i]) != vowels.end()) {
            max_vowels++;
        }
    }
    int current = max_vowels;
    int l = 0;
    for(int r = k; r < s.length(); ++r) {
        if(vowels.find(s[r]) != vowels.end()) {
            current++;
        }
        while(r-l+1 > k) {
            if(vowels.find(s[l]) != vowels.end()) {
                current--;
            }
            l++;
        }       
        max_vowels = std::max(max_vowels, current); 
    }
    return max_vowels;
}


int main() {
    std::string s = "abciiidef";
    int k = 3;
    //#Output: 3
    int result = max_number_vowels(s, k);
    std::cout << "result= " << result << std::endl;

    s = "aeiou";
    k = 2;
    //#Output: 2
    result = max_number_vowels(s, k);
    std::cout << "result= " << result << std::endl;


    s = "leetcode";
    k = 3;
    //#Output: 2
    result = max_number_vowels(s, k);
    std::cout << "result= " << result << std::endl;
}