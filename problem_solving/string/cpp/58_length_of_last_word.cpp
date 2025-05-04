/*'''
https://leetcode.com/problems/length-of-last-word/

important thing is to strip the blanks at the end

start from end.
    strip off spaces.
    iterate till next space
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


int length_of_last_word(const std::string& s) {
    if(s.empty()) {
        return 0;
    }
    int i = s.length()-1;
    while(i >= 0 && s[i]==' ') {
        i--;
    }
    int result = 0;
    while(i >= 0 && s[i] != ' ') {
        i--;
        result++;
    }
    return result;
}



int main() {
    std::string s;
    s = "Hello World";
    //#Output: 5
    //#Explanation: The last word is "World" with length 5.
    int l = length_of_last_word(s);
    std::cout << "length_of_last_word: " << l << std::endl;

    s = "   fly me   to   the moon  ";
    //#Output: 4
    //#Explanation: The last word is "moon" with length 4.
    l = length_of_last_word(s);
    std::cout << "length_of_last_word: " << l << std::endl;


    s = "luffy is still joyboy";
    //#Output: 6;
    //#Explanation: The last word is "joyboy" with length 6.
    l = length_of_last_word(s);
    std::cout << "length_of_last_word: " << l << std::endl;
}
