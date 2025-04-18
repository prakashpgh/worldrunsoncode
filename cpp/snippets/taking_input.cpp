#include<iostream>
#include<string>
#include<vector>

int main() {
    int count;
    std::cout << "How many integers would you like to input?" << std::endl;
    std::cin >> count;

    std::vector<int> numbers(count);

    std::cout << "Enter " << count << " integers separated by spaces:" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cin >> numbers[i];
        std::cout << numbers[i] << ",";
    }
}