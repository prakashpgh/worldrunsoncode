/*
Substitution failure is not error

*/

#include <iostream>
#include <type_traits>
// Function enabled only if T is an integral type
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
printIfIntegral(T value) {
    std::cout << "Integral value: " << value << std::endl;
}
// Function enabled only if T is a floating-point type
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
printIfFloatingPoint(T value) {
    std::cout << "Floating-point value: " << value << std::endl;
}
int main() {
    printIfIntegral(42);          // Works, as 42 is an integral type
    printIfFloatingPoint(3.14);   // Works, as 3.14 is a floating-point type
    return 0;
}


//////////////////////////////////////////////////////////////////
/*
concepts specify constraints on template parameters, ensuring that the types used in templates meet certain criteria
*/
#include <concepts>
#include <iostream>

template<typename T>
concept Integral = std::is_integral_v<T>;

template<Integral T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(3, 4) << std::endl; // Works fine
    return 0;
}

/////////////////////////////////////////////////////
