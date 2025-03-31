#include <algorithm>
#include <vector>
#include<iostream>

void print_array(const int arr[], size_t size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;
}




int main() {
    //sort array
    std::cout << "sort array " << std::endl;
    int arr[] = {5,2,9,1,5,6};
    size_t arr_size = sizeof(arr)/sizeof(arr[0]);
    std::sort(arr, arr + arr_size);
    print_array(arr, arr_size);

    //array in descending..
    std::cout << "reverse sort array " << std::endl;
    std::sort(arr, arr + arr_size, std::greater<int>());
    print_array(arr, arr_size);

    //sort array partially
    std::cout << "sort array partially" << std::endl;
    int partialArr[] = {10, 20, 5, 15, 30};
    size_t partialSize = sizeof(partialArr) / sizeof(partialArr[0]);

    std::sort(partialArr + 1, partialArr + 4); // Sort elements from index 1 to 3

    std::cout << "Partially sorted array: ";
    print_array(partialArr, partialSize);
}