/*
    easy way to write anonymous functions
    [capture-list](parameter-list) -> return-type { function-body }
        capture-list: =, &, this, &x, x

        >> lambda has the capture list
        >> more inlining opportunities for the compiler
        
        Usage:
                predicate functions for std::sort, std::for_each


    Other ways to call functions
    1) function pointers
            just have the address of the function

    2) function objects or functors
            class to encapsulate the function.

 */  


#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>


void lambda_usage() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int factor = 3;

    //case I
    // Lambda expression capturing 'factor' by value
    std::vector<int> multiplied_lambda;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(multiplied_lambda),
                   [factor](int n) { return n * factor; });


    //##########################
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (auto &i : v)
    {
        i++;
    }

    //A=> simple usage of lambda
    std::for_each(
        v.begin(), v.end(), [](auto i)
        { ++i; });

    std::cout << "printing: " << std::endl;
    for (auto i : v)
    {
        std::cout << i << ",";
    }   

    //#####################################
    //B=>capture by reference
    numbers = {1, 2, 3, 4, 5};
    int sum =  0;
    std::for_each(numbers.begin(), numbers.end(), [&sum](int n) { sum += n; });
    std::cout << "sum: " << sum << std::endl;

    //C
    std::vector<int> unsorted = {5, 2, 8, 1, 9};
    std::sort(unsorted.begin(), unsorted.end(), [](int a, int b) {return a < b; } );
    for (auto& i : unsorted) {
        std::cout << i << "     ";
    }

}


#include<functional>
int test_funct(int i) {
    std::cout << i << std::endl;
}

class Functor {
    public:
        void operator()(int x) const {
            std::cout << "Functor called with: " << x + 5 << std::endl;
        }
    };

//1) std::function can be used to call lambda functions.
//2) std::function can be used to call regular functions
//3) std::function can be used to call functors
void std_function() {
    std::function<int(int)> func_ptr = test_funct;
    func_ptr(10);
}


int main()
{
    std::cout << "lambda 0" << std::endl;
    lambda_usage();

    return 0;
}