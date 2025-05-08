/*
static_cast
    safe conversions between related types

dynamic_cast
    for polymorphic hierarchies..

    If the cast to a pointer type is successful, it returns a pointer to the derived object.
    If the cast to a pointer type fails (the object is not of the target derived type or a derived type), it returns nullptr.
    If the cast to a reference type fails, it throws a std::bad_cast exception

const_cast
    add or remove const/volatile

reinterpret_cast
    low level reinterpretation of data
 */



 #include <iostream>

class Base {
public:
    virtual void foo() { std::cout << "Base::foo()" << std::endl; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void foo() override { std::cout << "Derived::foo()" << std::endl; }
    ~Derived() override {}
    void derivedFunction() {}
};


void cast_test() {
    Base* basePtr1 = new Derived();
    Base* basePtr2 = new Base();

    Derived* derivedPtr1 = dynamic_cast<Derived*>(basePtr1); // Successful
    if (derivedPtr1) {
        derivedPtr1->derivedFunction();
    }

    Derived* derivedPtr2 = dynamic_cast<Derived*>(basePtr2); // Returns nullptr
    if (derivedPtr2 == nullptr) {
        std::cout << "Downcast failed." << std::endl;
    }

    Derived& derivedRef = dynamic_cast<Derived&>(*basePtr1); // Successful
    try {
        Derived& derivedRef2 = dynamic_cast<Derived&>(*basePtr2); // Throws std::bad_cast
    } catch (const std::bad_cast& e) {
        std::cerr << "Cast failed: " << e.what() << std::endl;
    }
}



int main() {
    Derived d;
    size_t* pVptr = reinterpret_cast<size_t*>(&d);
    std::cout << "Potential vptr address: 0x" << std::hex << *pVptr << std::endl;
    return 0;
}