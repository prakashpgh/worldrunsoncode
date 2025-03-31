#include <iostream>
#include <string>
#include <vector>

class MyString {
public:
    std::string data;

    MyString(std::string str) : data(std::move(str)) {
        std::cout << "_Constructor called" << std::endl;
    }

    // Move constructor
    MyString(MyString&& other) noexcept : data(std::move(other.data)) {
        std::cout << "M_ove constructor called" << std::endl;
    }

    // Copy constructor (crucial)
    MyString(const MyString& other) : data(other.data) {
        std::cout << "Copy constructor called" << std::endl;
    }

    // Destructor
    ~MyString(){
        std::cout << "Destructor called" << std::endl;
    }
};

MyString createString() {
    return MyString("Hello, World!"); // Returns a temporary MyString
}

int main() {
    MyString s1 = createString(); // Move constructor called (temporary object)

    std::string temp = "another string";
    MyString s2 = MyString(std::move(temp)); // Move constructor called (explicit move)

    std::vector<MyString> myVector;
    myVector.emplace_back("vector string"); // move constructor might be called, if the vector needs to resize.

    return 0;
}