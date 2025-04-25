/*
    easy way to write anonymous functions
    [capture-list](parameter-list) -> return-type { function-body }
        capture-list: =, &, this, &x, x

        >> lambda has the capture list
        >> more inlining opportunities for the compiler
        
        Usage:
                predicate functions for std::sort, std::for_each


    Other ways to call functios
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
    std::vector<int> numbers = {1, 2, 3, 4, 5};
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


int main()
{
    std::cout << "lambda 0" << std::endl;


    return 0;
}