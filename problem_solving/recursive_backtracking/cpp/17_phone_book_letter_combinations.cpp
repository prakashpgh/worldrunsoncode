/*
'''
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#meta
parameters:
    index of the digits in progress

choices: 
    pairing with different letters mapped to a digit

exit:
    the length of the result == number of digits
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
#include<math.h>


class Solve {
    private:
    std::vector<std::string> results;
    std::unordered_map<char, std::string> mapping = {
        {'2' , "abc"},
        {'3' , "def"},
        {'4' , "ghi"},
        {'5' , "jkl"},
        {'6' , "mno"},
        {'7' , "pqrs"},
        {'8' , "tuv"},
        {'9' , "wxyz"}
    };

    std::vector<std::string> recur(int index, const std::string& digits, std::string& combi) {
        
        if(index == digits.length()) {
            results.push_back(combi);
            return results;
        }

        char digit = digits[index];
        auto chars = mapping[digit];
        for(char c : chars) {
            combi.push_back(c);
            recur(index+1, digits, combi);
            combi.pop_back();
        }
        return results;
    }

    public:
    std::vector<std::string> phone_book_letter_combinations(std::string digits)  {
        if(digits.empty() ) {
            return {};
        }
        results.clear();
        std::string combi;
        results = recur(0, digits, combi);
        return results;
    }
    
};


    
int main()  {
    std::string digits = "23";
    Solve solve;
    auto result = solve.phone_book_letter_combinations(digits);
    print_vector(result);
    //#Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    
    digits = "";
    result = solve.phone_book_letter_combinations(digits);
    print_vector(result);
    //#[]
    
    digits = "2";
    result = solve.phone_book_letter_combinations(digits);
    print_vector(result);
    //#Output: ["a","b","c"]

}
