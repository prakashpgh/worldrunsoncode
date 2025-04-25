
/*
if with initalizer

switch with initializer

auto = compiler deduce the type

volatile => identifier for an variable, it tells the compiler not to do any optimization around it, used mostly in interfacing with hardare, signal handlers

constexpr

constexpr if


    

storage class for variables
    auto

    extern

    noexcept
        tells that the function is not going to throw... its an optimization,
        but if it throws then std::terminate is called.

    const keyword
        class TT {
            void get() const; => function does not change the member variables.
                                if the function wants to, then use mutable for data member.
        }

    static

    register

    mutable: make that particular datamemeber non-const in const functions.

    volatile: tell the compiler not to do optimizations, 
  
    inline:
        keyword hinting the compiler that the function call should be replaced by the actual code.
        its not guaranteed that the compiler would inline a function, it depends on the size of the function, complexity etc.    
        performance improvements: function call is eliminated, stack, jumps, returns
            good for small, frequently called funtions
            2) code caching: better instruction cache usage

            Cons: 1) code bloating...increased binary size
                    larger binaries can cause worse instruction cache performance
                2) increase compile time
                3) maintenance challenges: if its defined in a header and used across many files, changing it requires recompiling all dependant files.. slowing development
                4) debugging difficulty: inlined function may not appear in stack trace or debuggers
            USE FOR SMALL, FREQUENTLY CALLED FUNCTIONS            

functional header
    std::function<int(int, int)> operation;
    operation = [](int a, int b) { return a + b; };
    std::cout << "10 + 5 = " << operation(10, 5) << std::endl;

*/

/////////////////////////////////////////////////////////////////////////////////////
//std optionals
std::optional<std::string> findNameById(int id) {
    if (id == 1) {
        return "Alice";
    } else if (id == 2) {
        return "Bob";
    } else {
        return std::nullopt; // No value
    }
}

void std_optional_demo {
    auto name = findNameById(1);
    if (name) {
        std::cout << "Name found: " << *name << std::endl;
    } else {
        std::cout << "Name not found" << std::endl;
    }
    name = findNameById(3);
    if (name) {
        std::cout << "Name found: " << *name << std::endl;
    } else {
        std::cout << "Name not found" << std::endl;
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////
/*
std::variant

std::variant is a type-safe union that can hold one of several specified types, ensuring only one type is active at any given time.

*/
#include <iostream>
#include <variant>
#include <string>

using VarType = std::variant<int, float, std::string>;

void processVariant(const VarType& var) {
    std::visit([](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, int>) {
            std::cout << "Integer: " << arg << std::endl;
        } else if constexpr (std::is_same_v<T, float>) {
            std::cout << "Float: " << arg << std::endl;
        } else if constexpr (std::is_same_v<T, std::string>) {
            std::cout << "String: " << arg << std::endl;
        }
    }, var);
}

int main() {
    VarType v1 = 42;
    VarType v2 = 3.14f;
    VarType v3 = std::string("Hello, World!");

    processVariant(v1);
    processVariant(v2);
    processVariant(v3);

    return 0;
}

///////////////////////////////////////////////
constexpr if

#include <iostream>
#include <type_traits>

template <typename T>
void printTypeInfo(const T& value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "The value is an integral type: " << value << std::endl;
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "The value is a floating-point type: " << value << std::endl;
    } else {
        std::cout << "The value is of some other type: " << value << std::endl;
    }
}




int main() {
    printTypeInfo(42);          // Integral type
    printTypeInfo(3.14);        // Floating-point type
    printTypeInfo("Hello");     // Other type
    return 0;
}