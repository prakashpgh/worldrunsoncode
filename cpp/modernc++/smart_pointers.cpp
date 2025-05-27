/*
unique_ptr  
    single ownership
    movable

    Why have shared_ptr when shared_ptr can do everything unique_ptr can doe.
        shared_ptr has overhead => ref count, allocator, deallocator

        use unique_ptr as the first go...


shared_ptr  to share between objects/threads
    multiple ownership
    maintains ref counting
    move/copy allowed
        own the object and keep it alive
    control block:


weak_ptr    to break cycles or optional references to shared_ptr
    dont own the object
    does not have *, ->, get()  => you cannot gt the raw pointer

    std::shared_ptr<MyClass> sp2 = wp2.lock(); // get shared_ptr from weak_ptr

    wp.expired()
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



///////////////////////////////////////////////
//shared_ptr implementation

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

/////////////////////////////////////////////

class MyClass;

void someFunction(std::shared_ptr<MyClass> shareMe)
{
    std::cout << "someFunction: shareMe.use_count(): " << shareMe.use_count() << std::endl;
}

class MyClass : public std::enable_shared_from_this<MyClass>
{
public:
    std::shared_ptr<MyClass> getShared()
    {
        return shared_from_this();
    }
    void classMethod()
    {
        //....
        someFunction(getShared());
        //....
    }
};


void shared_ptr_references() {
    std::cout << std::endl;
    std::cout << "shared_ptr_references " << std::endl;

    std::shared_ptr<MyClass> shareMe(new MyClass);
    std::shared_ptr<MyClass> shareMe1 = shareMe->getShared();
    {
        auto shareMe2(shareMe1);
        std::cout << "main(): shareMe.use_count(): " << shareMe.use_count() << std::endl;
    }
    std::cout << "main(): shareMe.use_count(): " << shareMe.use_count() << std::endl;

    shareMe1.reset();

    std::cout << "main(): shareMe.use_count(): " << shareMe.use_count() << std::endl;

    shareMe->classMethod();

    std::cout << std::endl;
}
/////////////////////////////////

// Custom Allocator
template <typename T>
struct MyAllocator {
    using value_type = T;

    MyAllocator() noexcept = default;
    template <typename U> MyAllocator(const MyAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        std::cout << "Custom allocator: Allocating " << n * sizeof(T) << " bytes." << std::endl;
        T* ptr = static_cast<T*>(::operator new(n * sizeof(T)));
        if (!ptr) {
            throw std::bad_alloc();
        }
        return ptr;
    }

    void deallocate(T* p, std::size_t n) {
        std::cout << "Custom allocator: Deallocating " << n * sizeof(T) << " bytes." << std::endl;
        ::operator delete(p);
    }
};

template <typename T, typename... Args>
std::shared_ptr<T> make_shared_with_allocator(const MyAllocator<T>& alloc, Args&&... args) {
    // Note: std::allocate_shared is the way to go for custom allocators with make_shared,
    // but it requires the allocator to be copyable and stateful in some cases.
    // For simplicity in this example, we'll manually construct.

    // 1. Allocate memory using the custom allocator
    T* ptr = alloc.allocate(1);
    if (!ptr) throw std::bad_alloc();

    try {
        // 2. Construct the object in the allocated memory
        ::new (ptr) T(std::forward<Args>(args)...);

        // 3. Create the shared_ptr with a custom deleter that uses the custom allocator
        return std::shared_ptr<T>(ptr, [alloc](T* p) {
            std::cout << "Custom deleter called." << std::endl;
            p->~T(); // Explicitly call the destructor
            alloc.deallocate(p, 1);
        });
    } catch (...) {
        // Ensure we deallocate if construction fails
        alloc.deallocate(ptr, 1);
        throw;
    }
}

// Custom Deallocator (as a separate function object)
struct MyDeleter {
    void operator()(int* p) const {
        std::cout << "Custom deleter (function object) called for int." << std::endl;
        delete p;
    }
};


void using_custom_allocators() {
    std::cout << "--- Example 1: Custom Allocator and Deleter (via lambda) ---" << std::endl;
    {
        MyAllocator<int> intAllocator;
        //supported in c++ 20
        //auto sharedPtr1 = make_shared_with_allocator(intAllocator, 42);
        //std::cout << "Value in sharedPtr1: " << *sharedPtr1 << std::endl;
    } // sharedPtr1 goes out of scope, custom deleter and allocator deallocate

    std::cout << "\n--- Example 2: Custom Deleter (function object) with default allocator ---" << std::endl;
    {
        std::shared_ptr<int> sharedPtr2(new int(100), MyDeleter());
        std::cout << "Value in sharedPtr2: " << *sharedPtr2 << std::endl;
    } // sharedPtr2 goes out of scope, custom deleter (MyDeleter) is called

    std::cout << "\n--- Example 3: Custom Deleter (lambda) with default allocator ---" << std::endl;
    {
        std::shared_ptr<double> sharedPtr3(new double(3.14), [](double* p) {
            std::cout << "Custom deleter (lambda) called for double." << std::endl;
            delete p;
        });
        std::cout << "Value in sharedPtr3: " << *sharedPtr3 << std::endl;
    } // sharedPtr3 goes out of scope, custom deleter (lambda) is called
}

//////////////////////////////////////////////
//cyclic memory leak example

struct MyClassB;
struct MyClassA
{
    std::shared_ptr<MyClassB> b;
    ~MyClassA() { std::cout << "MyClassA::~MyClassA()\n"; }
};

struct MyClassB
{
    std::shared_ptr<MyClassA> a;
    ~MyClassB() { std::cout << "MyClassB::~MyClassB()\n"; }
};

void useClassAnClassB()
{
    std::cout << "cyclic memory leak example..." << std::endl;
    auto a = std::make_shared<MyClassA>();
    auto b = std::make_shared<MyClassB>();
    a->b = b;
    b->a = a;
}





int main() {
    test_unique_ptr();

    test_shared_ptr();

    test_weak_ptr();

    shared_ptr_references();

    useClassAnClassB();

    using_custom_allocators();
}
