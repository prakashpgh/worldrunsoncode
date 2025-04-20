/*
//default sorting is ascending
std::sort(vec.begin(), vec.end(), std::greater<int>)
std::sort(vec.begin(), vec.end(), lambda)
    custom sort.
    1) bool compare11(const Person& p1, const Peson& p2);
    2) bool operator<(const Person& p1, const Person& p2) 
    3) lambda  [] (const Person& p1, const Peson& p2) { }

std::reverse

//copy
std::vec destination(size)
std::copy(vec.begin(), vec.end(), destination)

std::array
    std::array<int, 5> = {}
    front
    back

std::fill => applies to vector, array, raw arrays, deque, list
*/
#include <algorithm>
#include <vector>
#include<iostream>
#include "../utils/utils.h"


void sorting_demo() {
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


void sorting_on_particular_key() {
    int sort_key = 1;//this is the sort key, can be 0,1 or other indices
    std::cout << "before sorting" << std::endl;
    std::vector<std::vector<int>> intervals = {{1, 3}, {9, 6}, {8, 10}, {15, 18}, {2, 9}};
    print_vector_of_vector(intervals);

    //sort on the basis of the first element
    std::sort(intervals.begin(), intervals.end(), [sort_key] (const std::vector<int>& a, const std::vector<int>& b) {
        return a[sort_key] < b[sort_key];
    });
    std::cout << "after sorting" << std::endl;
    print_vector_of_vector(intervals);
}


void frequency_counter() {
    std::vector<int> frequency(26, 0);//initializes with zero
    std::string s = "leetcode";
    for (const auto& ch : s) {
        frequency[ch - 'a']++;
    }
    print_vector(frequency);
}


void reverse_array_vector() {
    int array[] = {1,2,3,4,5};
    size_t size= sizeof(array) / sizeof(array[0]);
    std::cout << "before reverse" << std::endl;
    print_array(array, size);
    std::reverse(array, array+size);
    std::cout << "after reverse" << std::endl;
    print_array(array, size);

    //vector...
    std::cout << "before reverse" << std::endl;
    std::vector<int> vec = {1,2,3,4,5};
    print_vector(vec);
    std::reverse(vec.begin(), vec.end());
    std::cout << "after reverse" << std::endl;
    print_vector(vec);
    
}


void deep_copy() {
    const int source[] = {1,2,3,4,5};
    int size = sizeof(source) / sizeof(source[0]);
    if( source == nullptr) {
        //return nullptr;
    }
    int* destination = new int[size];
    std::copy(source, source + size, destination);
    print_array(destination,size);
}

void copy_vector() {
    std::vector<int> originalVector = {1, 2, 3, 4, 5};
    //print_vector(originalVector);
    //using copy constructor
    std::vector<int> copied = originalVector;
    print_vector(copied);

    //using assignment operator
    std::vector<int> copied_1;
    copied_1 = originalVector;
    print_vector(copied_1);

    //std::copy
    std::vector<int> copied_2(originalVector.size());//important.
    std::copy(originalVector.begin(), originalVector.end(), copied_2.begin());
    print_vector(copied_2);

    //range
    std::vector<int> copied_3(originalVector.size());//important.
    std::copy(originalVector.begin()+1, originalVector.end()-1, copied_3.begin());
    print_vector(copied_3);
}

//custom sort
class Person {
    public:
    Person(const std::string& name, int age) : name(name), age(age) {
    }
    bool operator<(const Person& rhs) {
        return age < rhs.age;
    }
    void print() const {
        std::cout << "person name:" << name << "," << "age:" << age << std::endl;
    }

    std::string name;
    int age;
};

// Custom comparison function for sorting by name
bool compareByName(const Person& p1, const Person& p2) {
    return p1.name < p2.name;
}

void custom_sort_demo() {
    std::vector<Person> persons = {
        {"one", 1},
        {"two", 2},
        {"three one", 31},
        {"four", 4},
        {"five", 5}
    };
    std::cout << "before sort" << std::endl;
    for (const auto& p : persons) {
        p.print();
    }

    std::cout << "after sort" << std::endl;
    std::sort(persons.begin(), persons.end());
    for (const auto& p : persons) {
        p.print();
    }

   //compare by name
   std::cout << "after sort by name..." << std::endl;
   std::sort(persons.begin(), persons.end(), compareByName);
    for (const auto& p : persons) {
        p.print();
    }    

    //using lambda...
   std::cout << "after sort by age using lambda..." << std::endl;
   std::sort(persons.begin(), persons.end(), [] (const Person& p1, const Person& p2) {
        return p1.age < p2.age;
   });
    for (const auto& p : persons) {
        p.print();
    }    

}


struct MyStruct {
    int id;
    std::string name;

    MyStruct(int id, const std::string& name) : id(id), name(name) {
        std::cout << "MyStruct constructor called: " << name << std::endl;
    }

    MyStruct(const MyStruct& other) : id(other.id), name(other.name) {
        std::cout << "MyStruct copy constructor called: " << other.name << std::endl;
    }

    MyStruct(MyStruct&& other) noexcept : id(other.id), name(std::move(other.name)) {
        std::cout << "MyStruct move constructor called: " << name << std::endl;
    }

    ~MyStruct() {
        std::cout << "MyStruct destructor called: " << name << std::endl;
    }
};


void vector_demo() {
    //sort vector
    std::cout << "sort vector " << std::endl;
    std::vector<int> vec = {8,3,10,4,7};
    std::sort(vec.begin(), vec.end());
    print_vector(vec);

    //sort vectorin reverse
    std::cout << "reverse sort array " << std::endl;
    std::sort(vec.rbegin(), vec.rend());
    print_vector<int>(vec);

    //    
    std::vector<int> initialNumbers = {1, 2, 3, 4, 5}; // Vector with initial values
    
    initialNumbers.push_back(10);
    initialNumbers.push_back(20);
    print_vector(initialNumbers);

    std::vector<std::string> names = {"Alice", "Bob", "Charlie"}; // Vector of strings
    print_vector(names);
    std::cout << names.back() << std::endl;
    names.pop_back();
    print_vector(names);

    //emplace back
    std::vector<MyStruct> myVector;
    //myVector.resize(3);

    std::cout << "Using push_back:" << std::endl;
    myVector.push_back(MyStruct(1, "Alice")); // Creates a temporary, copies or moves it.

    std::cout << "\nUsing emplace_back:" << std::endl;
    myVector.emplace_back(2, "Bob"); // Constructs the object directly in the vector.
}


//std::array
#include<array>
void std_array_demo() {
    std::array<int, 5> arr = {1,2,3,4,5};
    arr[2] = 31;
    std::cout << "front " << arr.front() << std::endl;
    std::cout << "back " << arr.back() << std::endl;

    int* data = arr.data();
    std::cout << "first element: " << *data << std::endl;
}

void multi_dim_vector() {
    int rows = 3;
    int cols = 3;
    std::vector<std::vector<int>> memo(rows, std::vector<int>(cols, -1));
    print_vector_of_vector(memo);
    std::cout << "resizing" << std::endl;
    rows=4;
    cols = 4;
    memo.resize(rows, std::vector<int>(cols, -2));
    print_vector_of_vector(memo);

    //3-dim vector..  lc 123 and 188
    std::vector<int> prices = {1,2,3,4,5,6};
    int n = prices.size();
    int k = 2;
    std::vector<std::vector<std::vector<int>>> dp( n, std::vector<std::vector<int>>(k+1, std::vector<int>(2, 0)));

}

void max_element() {
    std::vector<int> vec = {1,2,3,32,4,5,8,7};
    auto mx = std::max_element(vec.begin(), vec.end());
    std::cout << "max: " << *mx << std::endl;

    //max_element with custom
    mx = std::max_element(vec.begin(), vec.end(), std::greater<int>());
    std::cout << "max: " << *mx << std::endl;
}


int main() {
    //sorting_demo();

    //sorting_on_particular_key();

    //frequency_counter();

    vector_demo();
    //reverse_array_vector();

    //deep_copy();


    //copy_vector();

    //custom_sort_demo();

    //std_array_demo();

    multi_dim_vector();

    max_element();
}

