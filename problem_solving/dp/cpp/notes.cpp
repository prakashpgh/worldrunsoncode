/*
use std::numeric_limits<int>::max()
dont add to this, it will overflow.
e.g int i = std::numeric_limits<int>::max();
    i += 1;//
*/
#include<limits>
#include<iostream>

int main() {
    int i = std::numeric_limits<int>::max();
    std::cout << i << std::endl;
    i += 1;
    std::cout << i << std::endl;
}