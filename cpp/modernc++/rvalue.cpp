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

    MyString s1(s4);
    std::cout << "3" << std::endl;
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

    test_unique_ptr_move();

}
