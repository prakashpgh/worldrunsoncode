#include<iostream>

class ResourceHolder {
    public:
        int* data;
        int size;
    
        ResourceHolder(int sz) : size(sz) {
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = i;
            }
            std::cout << "Constructor called, allocated memory at: " << data << std::endl;
        }
    
        // Deep copy constructor
        ResourceHolder(const ResourceHolder& other) : size(other.size) {
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
            std::cout << "Copy constructor called, allocated new memory at: " << data << std::endl;
        }

        // Move constructor
        ResourceHolder(ResourceHolder&& other) noexcept
           : data(other.data), size(other.size) {
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move constructor called, transferred ownership of memory at: " << data << std::endl;
        }

        // Copy assignment operator
        ResourceHolder& operator=(const ResourceHolder& other) {
            std::cout << "Copy assignment operator called" << std::endl;
            if (this != &other) { // Handle self-assignment
                // 1. Release existing resources
                delete[] data;
                data = nullptr;
                size = 0;

                // 2. Allocate new resources and copy data
                size = other.size;
                data = new int[size];
                for (int i = 0; i < size; ++i) {
                    data[i] = other.data[i];
                }
            }
            return *this; // Return a reference to the current object
        }

        // Move assignment operator
        ResourceHolder& operator=(ResourceHolder&& other) noexcept {
            std::cout << "Move assignment operator called" << std::endl;
            if (this != &other) { // Handle self-move-assignment
                // 1. Release existing resources
                delete[] data;
                data = nullptr;
                size = 0;

                // 2. Transfer ownership
                data = other.data;
                size = other.size;

                // 3. Set the source object to a safe state
                other.data = nullptr;
                other.size = 0;
            }
            return *this;
        }

        ~ResourceHolder() {
            delete[] data;
            std::cout << "Destructor called, freed memory at: " << data << std::endl;
        }
    };
    
    void copy_constructor() {
        ResourceHolder h1(5);
        ResourceHolder h2 = h1; // Our deep copy constructor is called
    
        // Both h1.data and h2.data point to the same memory!
    
        // Problem: When h2 goes out of scope, its destructor will delete the memory.
        // Then, when h1 goes out of scope, its destructor will try to delete the same already freed memory, leading to a crash (double free).
    }

    ResourceHolder createHolder() {
        return ResourceHolder(10); // Returns a temporary object (rvalue)
        //** => Note this might also cause rvo return value optimization
        //rvo => return value optimization
        //nrvo => named return value optimization
    }

    void move_constructor() {
        ResourceHolder h1 = createHolder(); // Move constructor will likely be called
        ResourceHolder h2 = std::move(h1);   // Move constructor will likely be called
    }

    void assignment_operator() {
        ResourceHolder h1(5);
        ResourceHolder h2(3);
        h2 = h1; // Copy assignment operator called
    }
    
    int main() {
        copy_constructor();

        move_constructor();

        assignment_operator();



        return 0;
    }