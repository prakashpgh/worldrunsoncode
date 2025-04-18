/*
rvalue
    temporary object/value that does not exist beyond the expression
    not bound to a variable
    can be moved
    &&

    avoid deep copy of large objects.

    std::move => 
        transfer ownership of a resource, 
        perf. optimization to avoid deep copy

    lvalue:  i = 10;  


A move constructor is called in C++ when an object is being initialized with an rvalue, indicating that the source object's resources can be "moved" rather than copied. 


std::move
    lvalue => rvalue T&&

with unique_ptr
    std::unique_pt    
*/
#include<iostream>
#include<cstring>
#include <memory>

class Test {
public:
void process(int& i) {
    std::cout << "l-value: " << i << std::endl;
}

void process(int&& i) {
    std::cout << "r-value: " << i << std::endl;
}

};


class MyString {
    private:
    char* _data;
    int _size;
    public:
    MyString(char* data) {
        int len = std::strlen(data);
        _data = new char[len+1];
        std::strcpy(_data, data);
        std::cout << "MyString ()" << std::endl;
    }

    MyString(const MyString& copy) {
        if (_data)
            delete _data;
        _size = copy._size;
        _data = new char[_size+1];
        std::strcpy(_data, copy._data);
        std::cout << "MyString &" << std::endl;
    }

    //steals resources from the source, and nullifies the source
    MyString(MyString&& copy) {
        _size = copy._size;
        _data = copy._data;
        copy._size = 0;
        copy._data = nullptr;
        std::cout << "MyString &&" << std::endl;
    }

    ~MyString() {
        std::cout << "MyString ~ " << std::endl;
    }
};


class MyString123 {
public:
    std::string data;

    MyString123(std::string str) : data(std::move(str)) {
        std::cout << "Constructor called" << std::endl;
    } //constructor

    // Move constructor
    MyString123(MyString123&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Move constructor called" << std::endl;
    }

    // Copy constructor
    MyString123(const MyString123& other) : data(other.data) {
        std::cout << "Copy constructor called" << std::endl;
    }

    
    ~MyString123(){
        std::cout << "Destructor called" << std::endl;
    }
    
};

MyString123 createString() {
    return MyString123("Hello, World!"); // Returns a temporary MyString
}

#include<vector>
void move_demo() {
    MyString123 s1 = createString(); // Move constructor called (temporary object) //1
    std::string temp = "another string";
    MyString123 s2 = MyString123(std::move(temp));//2

    //std::vector<MyString123> myVector;
    //myVector.emplace_back("vector string"); // move constructor might be called, if the vector needs to resize.
}



void test_rvalue() {
    Test t;
    int x = 5;
    t.process(x);
    t.process(5);

    //
    MyString s("hello");
    std::cout << "2" << std::endl;

    MyString s4(std::move(s));
    std::cout << "4" << std::endl;

    //MyString s1(s4);
    //std::cout << "3" << std::endl;
}

void test_unique_ptr_move() {
    auto p = std::make_unique<int>(9);
    std::cout << *p << std::endl;

    std::cout << "before move..." << std::endl;
    auto p1 = std::move(p);
    std::cout << *p1 << std::endl;
    if(!p) {
        std::cout << "p is null" << std::endl;
    }
}



int main() {
    test_rvalue();

    //test_unique_ptr_move();

    //move_demo();
}
