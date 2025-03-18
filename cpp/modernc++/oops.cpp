#include <iostream>
//encapsulation


//inheritance


//virtual inheritance
//solves the diamond problem...   In below, D inherits from B & C, here x is ambiguous for D.  
// if B & C inherit virtually from A, this problem is solved
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


