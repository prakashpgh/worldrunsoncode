#include<ctime>
#include<iostream>
#include<cstdlib>

void test_random() {
    srand(time(0));
    int random = rand();
    std::cout << random << std::endl;

    int ranged_num = rand() % 100 + 1;
    std::cout << ranged_num << std::endl;
}

//gcd
#include<numeric>
void test_gcd() {
    int g = std::gcd(12, 16);
    std::cout << "gcd: " << g << std::endl;
}

//min & max
void test_min_max() {
    int i = INT_MIN;
    i = INT_MAX;
    
}


int main() {
    test_random();

    test_gcd();
}