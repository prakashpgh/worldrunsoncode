/*
//encapsulation


//inheritance


virtual function
    class A {
        virtual void test();
    };
    
    classs D : public A {
        void test() override;   => override is not necessary, but if we use it then its a safety net  if base signature changes 
                                    and good maintenance..for devs to know that this is overided
    };


//virtual inheritance
//solves the diamond problem...   In below, D inherits from B & C, here x is ambiguous for D.  
// if B & C inherit virtually from A, this problem is solved



*/

#include <iostream>
class A {
    public:
    int x;
};

class B : virtual public A{
    public:
    int i;
};


class C : virtual public A{
    public:
    int i;
};


class D : public B, public C {

};

/*
if a class has virtual functions, a v-table is created by the compiler.  its per class.   it holds the addresses of all virtual functions 
vPtr => v-table
https://www.geeksforgeeks.org/vtable-and-vptr-in-cpp/


Virtual Functions and Polymorphism: Virtual functions are the cornerstone of runtime polymorphism in C++. When you call a virtual function through a pointer or reference to a base class, the actual function that gets executed is determined at runtime based on the object's dynamic type (the type of the object in memory), not the static type of the pointer or reference.   

The Role of the v-table: To achieve this runtime dispatch, the compiler creates a v-table for each class that declares or inherits virtual functions. This v-table is essentially an array of function pointers. Each entry in the v-table corresponds to a virtual function in the class.   

The v-pointer: Each object of a class with virtual functions (or inherited virtual functions) contains a hidden pointer called the v-pointer (vptr). This vptr points to the v-table of the object's actual class

class Base {
public:
    virtual void foo() { std::cout << "Base::foo()" << std::endl; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void foo() override { std::cout << "Derived::foo()" << std::endl; }
    ~Derived() override {}
};

int main() {
    Derived d;
    size_t* pVptr = reinterpret_cast<size_t*>(&d);
    std::cout << "Potential vptr address: 0x" << std::hex << *pVptr << std::endl;
    return 0;
}
*/





//polymorphism
class Base {
    public:
    int x;

    Base() {
        std::cout << "Base() constructor" << std::endl;
    }

    Base(int x) {
        std::cout << "Base(int t) constructor" << std::endl;
        this->x = x;
    }

    virtual void display() {
        std::cout << "Base display: " << x << std::endl;
    }
    
};


class Child : public Base {
    public:
    Child(int t) : Base(t) {
        std::cout << "child(int t) constructor" << std::endl;
    }

    void display() {
        std::cout << "child display: " << x <<  std::endl;
    }
};




int main() {
    //virtual inheritance
    D d;
    std::cout << d.x << std::endl;


    //polymorphism
    Child c(4);
    c.display();


    //in this case, if the 
    Base* b = new Child(8);
    b->display();
}


