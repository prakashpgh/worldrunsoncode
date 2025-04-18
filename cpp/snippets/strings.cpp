#include<vector>
#include<string>
#include<cctype>
#include "../utils/utils.h"

//frequency counters
void frequency_counter(const std::string& s) {
    std::vector<int> arr(26, 0);
    for( auto c : s) {
        arr[c - 'a'] += 1;
    }
    print_vector(arr);
}


void miscell() {
    char c = 'c';
    //std::isalnum 
    //std::isalpha
    //std::isdigit
    //std::isalnum
    
    std::cout << c << "=>" << std::isalnum(c) << std::endl;
    c = '$';
    std::cout << c << "=>" << std::isalnum(c) << std::endl;

    //std::tolower()   std::toupper()
    c = 'A';
    std::cout << c << "=>" << char(std::tolower(c)) << std::endl;

    //length
    s = "test is leng";
    int len = s.length();

    //empty
    bool em = s.empty();

    //access
    auto ch = s[4];

    //substr
    s = "hello";
    std::string sub = s.substr(1,3);//ell

    //push_back
    s.push_back('!');//hello!

    //append
    s.append("world");

    //insert
    s.insert(4, "testing");

    //erase
    s.erase(4, 3);//erase starting at index 4, with length 3

    //find
    s = "hello world world";
    size_t pos = s.find("world");//6

    //rfind
    size_t pos = s.find("world");//12

    //compare
    std::string s1 = "apple";
    std::string s2 = "banana";
    int result = s1.compare(s2); // result < 0

    //string conversions
    /*
    std::stoi()
    std::stol
    std::stoll
    std::stod
    std::to_string()  => convert numbe to string
    */
}



int main() {
    std::string s = "A man, a plan, a canal: Panama";
    frequency_counter(s);

    miscell();
}