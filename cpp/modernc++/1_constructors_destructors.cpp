#include <iostream>

/*
rule of 5
explicit pre => for constructor

noexcept => optimization
=delete
=default
friend

constructor:
    multiple constructors can be defined by overloading
    if no constructors defined, then there is default constructor provided.
    if constructor defined, there is no default constructor

        its okay to throw exceptions from constructor..


    explicit constructor
        if constructor is not marked as explicit, it will be called where object 
        is not instatiated explicitly, and cause subtle errors

    class FileName {
        public:
        explicit FileName(const std::string& name) : name_(name) {
            std::cout << "FileName constructor called with: " << name << std::endl;
        }
    }

    void printFileName(const FileName& fn) {
        std::cout << "File name: " << fn.getName() << std::endl;
    }

    int main() {
        printFileName("hello"); // Implicit conversion!
        FileName fileName = std::string("hello");  // Implicit conversion!
        return 0;
    }

    >> if the constructor would not have been explicit, then the 
            printFileName("data.csv") would have called the constructor
        if explicit key word is present, we need 
            printFileName(FileName("config.ini")); 

    
    >> initializer list
    1) Initialization of primitives
        init of primitivs

    2) initialization of const and references
                    class MyClass {
                            private:
                                const int constantValue;
                                int& referencedValue;
                                std::string name;

                            public:
                                // Constructor with member initializer list
                                MyClass(int initialValue, int& ref, const std::string& n)
                                    : constantValue(initialValue), // Initialize const member
                                    referencedValue(ref),        // Initialize reference member
                                    name(n)                      // Initialize regular member
                                {
                                }
                    }
    3) efficiency & performance
        default constructor called.  and then assign the value in the constructor body.
        initialization order is decided by the order in which the variables are declared.., not their order in the init list



-----------------------------------------------------------------------------------
destructor
    only 1 destructor 
    virtual destructor
    we need a virtual destructor, else the derived class destructor is not called.. in case of polymorphic.

    throwing exception in destructor
        ** if exception is thrown from the destructor terminate is called.
        
        consider this scenario..
        there is an exception thrown.
            the stack is being unwind & all the object's in the stack => destructors are being called.
            now, if any of the destructors throw an exception, now the question for the compiler which exception should it handle.. the first one or the one from ~
            so the state of the program enters an undefined state.
            In short, when an exception is thrown when a stack is unwinded, then std::terminate is called.

    delete [] => delete array
        class A {
            virtual ~A() {}
        }
        class B() {
            ~B() {}
        }
        A* = new B(); => if destructor is not virtual, base class destructor is not called.
-----------------------------------------------------------------------------------------------------

copy constructor
    class Test {
        Test(const Test& other) {}
    }
    Test t;
    Test t1 = t; 
    Test t2(t)
    => need to implement when we need some deep copy.
-----------------------------------------------------------------------------------------
assignment operator
        ClassName& operator=(const ClassName& other) {
            if this == &other { return; }

            return *this;
        }
    class Test {}
    Test t;
    Test t2;
    t2 = t1;
-----------------------------------------------------------------------------------------
move constructor:
    Should be used when the contents can be transferred rather than copy

    1) called when an object is initialized from rvalue
            std::move
    MyClass(MyClass&& other) {
    }
        MyClass obj1();
        MyClass c = std::move(obj1)
    }

    std::move

    std::move explicitly casts a lvalue to rvalue reference
    Note std::move itself does not make the move, it just enables the move constructor / move assignment operator to be called

            int main() {
                MyVector v1;
                MyVector v2 = std::move(v1); // Move constructor will be used for v2
                MyVector v3;
                v3 = std::move(v2);         // Move assignment operator will be used for v3
                // After the move, v1 and v2 will be in a valid but unspecified state.
                return 0;
        }
        
    2) Returning a non-primitive object from a function: 
        When an object is returned by value from a function, and the compiler can elide the copy.
        Note that if a move constructor is not defined, then the copy constructor is called.

    3) Passing a temporary object as a function argument:

            void processVector(MyVector v) {
                // ... use v ...
            }

            MyVector getTemporaryVector() {
                return MyVector();
            }

            int main() {
                processVector(getTemporaryVector()); // Move constructor will likely be used
                return 0;
            }

    4) when an object is instantiated from a temporary object.

            MyVector getAnotherTemporaryVector() {
                return MyVector();
            }

            int main() {
                MyVector v = getAnotherTemporaryVector(); // Move constructor will likely be used
                return 0;
            }

5) many STL algorithms are optimized to use move during many of the operations - which is beneficial during resizing, inserting, sorting
        MyClass obj1;
        MyClass obj2 = obj1;       // Copy constructor is called (obj1 is an lvalue)
        MyClass obj3 = MyClass();  // Move constructor is called (MyClass() is an rvalue)
        MyClass obj4 = std::move(obj1); // Move constructor is called (std::move(obj1) is an rvalue reference)
        obj3 = obj1;               // Copy assignment operator is called (obj1 is an lvalue)
        obj3 = MyClass();          // Move assignment operator is called (MyClass() is an rvalue)
        obj3 = std::move(obj1);    // Move assignment operator is called (std::move(obj1) is an rvalue reference)
---------------------------
Move assignment
    ClassName& operator=(ClassName&& other);

rule of 0
    if the class does not manage resources, only simple data types, you dont need any of these

rule of 5:
If your class manager memory, you should defind all 5
if the class needs any of the following, it probably needs all 5
    Destructor
    Copy constructor
    Move constructor
    Copy assignment operator
    Move assignment operator.    

------------------------------------------------------------------------------------

= delete
    => to explicitly prevent the compiler from generating certain default member functions.
        MyClass() = delete

        class NonCopyable {
        public:
            NonCopyable() = default;

            // Prevent copy construction
            NonCopyable(const NonCopyable&) = delete;

            // Prevent copy assignment
            NonCopyable& operator=(const NonCopyable&) = delete;

            void doSomething() const {
                std::cout << "NonCopyable object doing something." << std::endl;
            }
        };

        to prevent unwanted coppying or moving.
            e.g for file handles, mutexes, 
----------------------
=default
    is a feature in C++11 and later that you can use to explicitly request the compiler to generate the default implementation for certain special member functions. 
    used when your class have primitives, and NO resources needing special resource handlers.



    class Base {
        public:
            virtual ~Base() = default;
            virtual void someMethod() {}
        };

        class Derived : public Base {
        public:
            ~Derived() override = default;
            void someMethod() override {}
        };
-----------------------------

friend function:
    function which has access to all the members of a class including private members

----------------------------------------------------------------------
noexcept    
    the keyword tells that this function will not throw exception, 
    if an exception passes out of this function, std::terminate is called.

    e.g destructor has noexcept 
    1) it helps the compile and run-time understand a function is guaranteed not to throw any exceptions.
    2) move semantics: Standard Library containers rely on noexcept move operations for strong exception safety guarantees during resizing or other operations.

    Unconditional
        void f() noexcept {
            // This function is guaranteed not to throw any exceptions
        }
    Conditional
        void g() noexcept(true) {
            // This function is guaranteed not to throw any exceptions
        }

        void h() noexcept(false) {
            // This function might throw exceptions
        }

        template <typename T>
        void i() noexcept(std::is_nothrow_move_constructible_v<T>) {
            // This function is noexcept if T's move constructor is noexcept
        }

    when to use: when you are certain it will not throw... simple operations, move construct/assignment
------------------------------------------------------------------------------------------

this => pointer to self
---------------------------------

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

    MyVector& operator=(const MyVector& rhs) {
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
        //1=> delete any self memory
        delete [] data;
        
        //2=> steal the rhs memory and data
        data = rhs.data;
        size = rhs.size;
        capacity = rhs.capacity;
        //3=> nullify the rhs
        rhs.size = 0;
        rhs.capacity = 0;
        rhs.data = nullptr;//** this is very important to avoid double de-allocation */

        std::cout << "move operator" << std::endl;
        return *this;
    }
};


void polymorphism() {
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
}
////////////////////////////////////////////////////////////////////
//object slicing => when derived class is assigned to base class
void object_slicing() {
    Monkey m1(9);
    Animal a = m1;
}



int main() {

    polymorphism();

    //delete []
    int* p_i = new int[8];
    delete [] p_i;

}



///////////////////////////////////////////////////////////////////////////////////////////

