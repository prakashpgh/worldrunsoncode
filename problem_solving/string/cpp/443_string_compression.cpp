/*'''
https://leetcode.com/problems/string-compression/

this seems easy problem.. but is quite tricky..
#interesting
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


int string_compression(std::vector<char>& chars) {
    int write = 0;
    int read = 0;

    while (read < chars.size()) {
        char currentChar = chars[read];
        int count = 0;
        while (read < chars.size() && chars[read] == currentChar) {
            count++;
            read++; // This line increments the read pointer
        }

        chars[write++] = currentChar;

        if (count > 1) {
            std::string countStr = std::to_string(count);
            for (char c : countStr) {
                chars[write++] = c;
            }
        }
    }

    return write;
}

int main() {
    std::vector<char> chars = {'a','a','b','b','c','c','c'};
    //#Output: Return 6, and the first 6 characters of the input array should be: ['a','2','b','2','c','3']
    int result = string_compression(chars);
    print_vector(chars);
    std::cout << "result=" << result << std::endl; 
    
    
    
    chars = {'a'};
    //#Output: Return 1, and the first character of the input array should be: ['a']
    result = string_compression(chars);
    print_vector(chars);
    std::cout << "result=" << result << std::endl; 
    
    
    chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    //#Output: Return 4, and the first 4 characters of the input array should be: ['a','b','1','2'].
    result = string_compression(chars);
    print_vector(chars);
    std::cout << "result=" << result << std::endl; 
    
}
