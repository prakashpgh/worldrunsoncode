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

int main() {
    test_random();
}