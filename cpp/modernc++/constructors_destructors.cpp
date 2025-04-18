#include <iostream>

/*
constructor:
    multiple constructors can be defined by overloading
    if no constructors defined, then there is default constructor provided.
    if constructor defined, there is no default constructor

        its okay to throw exceptions from constructor..
------------------
destructor
    only 1 destructor 
    virtual destructor
    we need a virtual destructor, else the derived class destructor is not called.. in case of polymorphic.

    if exception is thrown from the destructor terminate is called.



    delete [] => delete array
        class A {
            virtual ~A() {}
        }
        class B() {
            ~B() {}
        }
        A* = new B(); => if destructor is not virtual, base class destructor is not called.
---------------------

copy constructor
    class Test {
        Test(const Test& other) {}
    }
    Test t;
    Test t1 = t; 
    Test t2(t)
    => need to implement when we need some deep copy.
-------------------------
assignment operator
        ClassName& operator=(const ClassName& other) {
            if this == &other { return; }

            return *this;
        }
    class Test {}
    Test t;
    Test t2;
    t2 = t1;
--------------------------
move constructor:
    Should be used when the contents can be transferred rather than copy

        1) called when an object is initialized from rvalue

    MyClass(MyClass&& other) {
    }
        MyClass obj1();
        MyClass c = std::move(obj1)
    std::move
        2) When an object is returned by value from a function, and the compiler can elide the copy.
    Note that if a move constructor is not defined, then the copy constructor is called.
---------------------------
Move assignment
    ClassName& operator=(ClassName&& other);

rule of 0
    if the class does not manage resources, only simple data types, you dont need any of these

rule of 5:
If your class manager memory, you should defind all 5
    Destructor
    Copy constructor
    Move constructor
    Copy assignment operator
    Move assignment operator.    

= delete
    => to explicitly prevent the compiler from generating certain default member functions.
        MyClass() = delete


friend function:
    function which has access to all the members of a class including private members

noexcept    
    the keyword tells that this function will not throw exception, if an exception passes out of this function, std::terminate is called.
    e.g destructor has noexcept 



this => pointer to self


#include <iostream>
#include <string>

class MyString {
public:
    std::string data;

    MyString(std::string str = "") : data(str) {
        std::cout << "Constructor called." << std::endl;
    }

    MyString(const MyString& other) : data(other.data) {
        std::cout << "Copy constructor called." << std::endl;
    }

    MyString(MyString&& other) : data(std::move(other.data)) {
        std::cout << "Move constructor called." << std::endl;
    }

    MyString& operator=(const MyString& other) {
        data = other.data;
        std::cout << "Copy assignment called." << std::endl;
        return *this;
    }

    MyString& operator=(MyString&& other) {
        data = std::move(other.data);
        std::cout << "Move assignment called." << std::endl;
        return *this;
    }
};

MyString createMyString() {
    return MyString("Temporary String");
}

int main() {
    MyString s1("Original String");
    MyString s2;

    // Move assignment operator (rvalue from function return)
    s2 = createMyString();

    // Move assignment operator (explicit move)
    s2 = std::move(s1);

    return 0;
}
*/


class Animal {
    public:
    Animal(int i) : id(i) {
        std::cout << "Animal constructor: " << id << std::endl;
    }


    //virtual destructor
    virtual ~Animal() {
        std::cout << "Animal destructor " << std::endl;
        //throw std::runtime_error("runtime exception...");
    }

    int id;
};


class Monkey : public Animal{
    public:
    Monkey(int id) : Animal(id) {
        std::cout << "Monkey constructor " << this->id << std::endl;
    }

    ~Monkey() {
        std::cout << "Monkey destructor " << id << std::endl;
    }
};

//-----------

class MyVector {
public:
    int* data;
    size_t size;
    size_t capacity;

    MyVector(int cap) : capacity(cap) {
        data = new int[cap];
        std::cout << "constructor" << std::endl;
    }

    ~MyVector() {
        delete [] data;
        std::cout << "destructor" << std::endl;
    }

    MyVector(const MyVector& rhs) {
        delete [] data;
        size = rhs.size;
        capacity = rhs.capacity;
        data = new int[capacity];
        for (size_t i = 0; i < rhs.size; ++i) {
            data[size++] = i;
        }
        std::cout << "copy constructor" << std::endl;
    }

    MyVector& operator&(const MyVector& rhs) {
        if (this == &rhs) {
            return *this;
        }
        delete [] data;
        size = rhs.size;
        capacity = rhs.capacity;
        data = new int[capacity];
        for (size_t i = 0; i < rhs.size; ++i) {
            data[size++] = i;
        }
        std::cout << "assignment operator" << std::endl;
        return *this;
    }

    MyVector(MyVector&& rhs) {
        data = rhs.data;
        size = rhs.size;
        capacity = rhs.capacity;
        rhs.data = nullptr;
        rhs.size = 0;
        rhs.capacity = 0;
        std::cout << "move constructor" << std::endl;
    }

    MyVector& operator=(MyVector&& rhs) {
        if (this == &rhs) {
            return *this;
        }
        delete [] data;
        
        data = rhs.data;
        size = rhs.size;
        capacity = rhs.capacity;
        rhs.size = 0;
        rhs.capacity = 0;
        rhs.data = nullptr;//** this is very important to avoid double de-allocation */

        std::cout << "move operator" << std::endl;
    }
};




int main() {
    Animal animal(5);

    std::cout << "id: " << animal.id << std::endl;

    Monkey m(4);
    std::cout << "id: " << m.id << std::endl;

    {
        std::cout << "start polymorphic..."  << std::endl;
        Animal* a = new Monkey(6);
        delete a;
        std::cout << "end polymorphic..."  << std::endl;
    }

    //delete []
    int* p_i = new int[8];
    delete [] p_i;

}



