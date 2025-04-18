
/*
if with initalizer

switch with initializer

auto = compiler deduce the type

volatile => identifier for an variable, it tells the compiler not to do any optimization around it, used mostly in interfacing with hardare, signal handlers

constexpr
    

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
