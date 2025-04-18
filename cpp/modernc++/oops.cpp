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

if a class has virtual functions, a v-table is created by the compiler.  its per class.   it holds the addresses of all virtual functions 
vPtr => v-table
https://www.geeksforgeeks.org/vtable-and-vptr-in-cpp/


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


