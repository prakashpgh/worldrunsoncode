
/*
if with initalizer

switch with initializer

auto = compiler deduce the type

volatile => identifier for an variable, it tells the compiler not to do any optimization around it, used mostly in interfacing with hardare, signal handlers

storage class for variables
    auto

    extern

    static

    register

    mutable: make that particular datamemeber non-const in const functions.

    volatile: tell the compiler not to do optimizations, 
  
functional header
    std::function<int(int, int)> operation;
    operation = [](int a, int b) { return a + b; };
    std::cout << "10 + 5 = " << operation(10, 5) << std::endl;

*/
