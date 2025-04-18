#include <iostream>

template <typename T>
class shared_ptr {
public:
    explicit shared_ptr(T* ptr = nullptr) : ptr_(ptr), count_(ptr ? new size_t(1) : nullptr) {}

    shared_ptr(const shared_ptr& other) : ptr_(other.ptr_), count_(other.count_) {
        if (count_) {
            ++(*count_);
        }
    }

    shared_ptr(shared_ptr&& other) noexcept : ptr_(other.ptr_), count_(other.count_) {
        other.ptr_ = nullptr;
        other.count_ = nullptr;
    }

    shared_ptr& operator=(shared_ptr other) {
        swap(other);
        return *this;
    }

    ~shared_ptr() {
        release();
    }

    T* get() const {
        return ptr_;
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    size_t use_count() const {
        return count_ ? *count_ : 0;
    }

    explicit operator bool() const {
        return ptr_ != nullptr;
    }

private:
    T* ptr_;
    size_t* count_;

    void release() {
        if (count_) {
            --(*count_);
            if (*count_ == 0) {
                delete ptr_;
                delete count_;
                ptr_ = nullptr;
                count_ = nullptr;
            }
        }
    }

    void swap(shared_ptr& other) {
        std::swap(ptr_, other.ptr_);
        std::swap(count_, other.count_);
    }
};

// Example usage:
struct MyStruct {
    int value;
    ~MyStruct() { std::cout << "MyStruct destroyed\n"; }
};

int main() {
    shared_ptr<MyStruct> ptr1(new MyStruct{42});
    std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl;

    shared_ptr<MyStruct> ptr2 = ptr1;
    std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl;
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;

    {
        shared_ptr<MyStruct> ptr3(ptr2);
        std::cout << "ptr1 use_count: " << ptr1.use_count() << std::endl;
        std::cout << "ptr2