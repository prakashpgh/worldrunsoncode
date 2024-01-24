#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

int main()
{
    std::cout << "lambda 0" << std::endl;

    std::vector<int> v = {1, 2, 3, 4, 5};
    for (auto &i : v)
    {
        i++;
    }

    //simple usage of lambda
    std::for_each(
        v.begin(), v.end(), [](auto i)
        { ++i; });

    std::cout << "printing: " << std::endl;
    for (auto i : v)
    {
        std::cout << i << ",";
    }   

    return 0;
}