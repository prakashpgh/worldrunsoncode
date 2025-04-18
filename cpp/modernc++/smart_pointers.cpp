/*
unique_ptr  
    single ownership
    movable

shared_ptr  to share between objects/threads
    multiple ownership
    maintains ref counting
    move/copy allowed
        own the object and keep it alive


weak_ptr    to break cycles or optional references to shared_ptr
    dont own the object

 */

 #include<memory>
 #include<iostream>


class Test {
private:
    int _data;
public:
    Test(int data) : _data(data) 
    {
        std::cout << "Test constructor" << std::endl;
    }

    ~Test() 
    {
        std::cout << "Test destructor" << std::endl;
    }
};


void test_unique_ptr() {
   std::unique_ptr<Test> tp = std::make_unique<Test>(3);
   std::unique_ptr<Test> tp2 = std::move(tp);

}

void test_shared_ptr() {
    std::cout << "testing shared_ptr" << std::endl;
    auto sp_1 = std::make_shared<Test>(3);
    std::cout << "use_count: " << sp_1.use_count() << std::endl;
    {
        auto sp_2 = sp_1;
        std::cout << "use_count: " << sp_1.use_count() << std::endl;
    }
    std::cout << "use_count: " << sp_1.use_count() << std::endl;
}


struct Node {
    int _val = 0;
    Node(int val) : _val(val) {
        std::cout << "Node ()" << std::endl;
    }

    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
    ~Node() {
        std::cout << "Node ~" << std::endl;
    }
};


void test_weak_ptr() {
    std::cout << "test_weak_ptr." << std::endl;
    auto p1 = std::make_shared<Node>(2);
    auto p2 = std::make_shared<Node>(3);
    p1->next = p2;
    p2->prev = p1;
    std::cout << "p1 ref.." << p1.use_count() << std::endl;
    std::cout << "p2 ref.." << p2.use_count() << std::endl;
    if (auto locked = p2->prev.lock()) {
        std::cout << "p1 ref.." << p2.use_count() << std::endl;
    }


    // Create a shared_ptr, which owns the MyObject
    std::shared_ptr<Node> sharedObj = std::make_shared<Node>(42);

    // Create a weak_ptr that observes the MyObject
    std::weak_ptr<Node> weakObj = sharedObj;

    // Check if the weak_ptr is still valid
    if (auto sharedFromWeak = weakObj.lock()) { // Attempt to get a shared_ptr
        std::cout << "Weak pointer is valid. Value: " << (*sharedFromWeak)._val << std::endl;
    } else {
        std::cout << "Weak pointer is expired." << std::endl;
    }

    // Release the shared_ptr, causing the MyObject to be destroyed
    sharedObj.reset();

    // Check the weak_ptr again
    if (auto sharedFromWeak = weakObj.lock()) {
        std::cout << "Weak pointer is valid. Value: " << (*sharedFromWeak)._val << std::endl;
    } else {
        std::cout << "Weak pointer is expired." << std::endl; // This will print
    }
}





#include <iostream>

template <typename T>
class SharedPtr {
private:
    T* ptr;
    int* refCount;

public:
    // Constructor
    SharedPtr(T* p = nullptr) : ptr(p) {
        if (ptr) {
            refCount = new int(1);
        } else {
            refCount = new int(0);
        }
    }

    // Copy constructor
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), refCount(other.refCount) {
        if (ptr) {
            (*refCount)++;
        }
    }

    // Move constructor
    SharedPtr(SharedPtr&& other) : ptr(other.ptr), refCount(other.refCount) {
        other.ptr = nullptr;
        other.refCount = nullptr;
    }

    // Assignment operator
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release(); // Release current resources
            ptr = other.ptr;
            refCount = other.refCount;
            if (ptr) {
                (*refCount)++;
            }
        }
        return *this;
    }

    //Move assignment operator
    SharedPtr& operator=(SharedPtr&& other){
        if(this != &other){
            release();
            ptr = other.ptr;
            refCount = other.refCount;
            other.ptr = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }

    // Destructor
    ~SharedPtr() {
        release();
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Arrow operator
    T* operator->() const {
        return ptr;
    }

    // Get raw pointer
    T* get() const {
        return ptr;
    }

private:
    void release() {
        if (ptr && --(*refCount) == 0) {
            delete ptr;
            delete refCount;
            ptr = nullptr;
            refCount = nullptr;
        }
    }
};


void shared_pointerd_impl() {
    SharedPtr<int> ptr1(new int(10));
    std::cout << *ptr1 << std::endl; // Output: 10

    SharedPtr<int> ptr2 = ptr1; // Copy constructor
    std::cout << *ptr2 << std::endl; // Output: 10

    SharedPtr<int> ptr3;
    ptr3 = ptr1;

    {
        SharedPtr<int> ptr4(new int(20));
        ptr3 = std::move(ptr4);
    } //ptr4 is destroyed here. ptr3 now points to 20

    std::cout << *ptr3 << std::endl;

}




int main() {
    test_unique_ptr();

    test_shared_ptr();

    test_weak_ptr();
}
