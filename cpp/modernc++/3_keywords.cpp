

void key_words() {
//const

//mutable

//constexpr
    //constexpr allows the evaluation of functions and expressions at compile time reducing the run-time computations.
    //a constexpr function can be evaluated at compile time if its arguments are known at compile time.
    constexpr int factorial(int n) {
        return (n <= 1) ? 1 : (n * factorial(n - 1));
    }

    int main() {
        constexpr int result = factorial(5); // result is 120
        return 0;
    }

//volatile
    this tells the compiler not to do any optimizations for this variable.
    something else can change this variable behind your back.
    
    1) e.g variables that might be directly modified by hardware registers.

    // Example: Reading a status register from a hardware device
    volatile unsigned int* statusRegister = (volatile unsigned int*)0x12345678;
    if (*statusRegister & 0x01) {

    2) variables can be4 modified by isr (interrupt service routine)

volatile will tell the compiler
        Disable caching in registers:
        Prevent dead code elimination
        Prevent instruction reordering 

//likely unlikely  => hint to compiler if the code is going to be executed with high frequency




int main() {

}