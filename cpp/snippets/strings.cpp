#include<vector>
#include<string>
#include<cctype>
#include "../utils/utils.h"
#include <sstream>

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
    std::string s = "test is leng";
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
    pos = s.find("world");//12

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

    //char to int => minus '0'
    c  = '6';
    int i = c;
    int j = c - '0';
    std::cout << "into to char " << ch << "=>" << i << "=>" << j << "=>" << std::endl;
    //into to char.  plus '0'
    i = 8;
    c = i;
    char c1 = i + '0';
    std::cout << "char to int: " << c << "=>" << i << "=>" << c1 << "=>" << std::endl;

    //std::swap
    s = "hello";
    int l = 0;
    int r = s.length() - 1;
    while(l < r) {
        std::swap(s[l], s[r]);
        l++;
        r--;
    }
    std::cout << "after swap: " << s << std::endl;
}


void parse_strings()  {
    //breaking string into words..
    s = "apple a day keeps doctor away";
    std::stringstream ss(s);
    std::string word;
    while(ss >> word) {
        std::cout << word << ",";
    }
    std::cout << std::endl;

    //
    std::string csv_line = "value1,value2,another value,last_value";
    std::istringstream iss(csv_line);
    std::string segment;
    std::vector<std::string> values;

    while (std::getline(iss, segment, ',')) {
        values.push_back(segment);
    }
}



int main() {
    std::string s = "A man, a plan, a canal: Panama";
    frequency_counter(s);

    miscell();
}