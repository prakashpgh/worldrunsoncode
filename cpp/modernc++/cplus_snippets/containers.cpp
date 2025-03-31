#include<iostream>


#include<algorithm>
#include<vector>

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

template<typename T>
void print_vector(const std::vector<T>& vec) {
    for( auto i : vec) {
        std::cout << i << ",";
    }
    std::cout << std::endl;
}


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


#include<stack>
/*
push
empty
top
pop
*/
void stack_demo() {
    std::stack<int> myStack;
    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Check if the stack is empty
    if (myStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    // Get the top element (without removing it)
    std::cout << "Top element: " << myStack.top() << std::endl;

    // Pop elements from the stack
    std::cout << "Popping elements:" << std::endl;
    while (!myStack.empty()) {
        std::cout << myStack.top() << std::endl;
        myStack.pop();
    }

}

#include<list>
template<typename T>
void print_list(const std::list<T>&  lst) {
    // Iterate through the list and print elements
    std::cout << "List elements: ";
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;    
}

/*
push_front
push_back
pop_front
pop_back
insert
remove
size()
empty()
//std::next(myList.begin(), 2); // Iterator to the 3rd element
*/
void list_demo() {
    std::list<int> myList = {1, 2, 3, 4, 5};

    // Add elements to the front and back of the list
    myList.push_front(0);
    myList.push_back(6);
    print_list(myList);

    // Insert an element at a specific position
    auto it = std::next(myList.begin(), 2); // Iterator to the 3rd element
    myList.insert(it, 10);    
    print_list(myList);

    // Remove elements
    myList.pop_front();
    myList.pop_back();
    myList.remove(3); // Removes all elements with value 3
    print_list(myList);

    if(myList.empty()) {
        std::cout << "list is empty" << std::endl;
    } else {
        std::cout << "size: " << myList.size() << std::endl;
    }


}

#include<string>
#include<map>

template<typename K, typename V>
void print_map(const std::map<K, V>& my_map) {
    for(const auto& pair : my_map) {
        std::cout << pair.first << "=>" << pair.second << std::endl;
    }
}


/*
[k] = val
insert(std::pair)
find
*/
void map_demo() {
    std::map<std::string, int> ageMap;
    // Insert key-value pairs into the map
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;
    ageMap.insert(std::make_pair("David", 28)); // Another way to insert

    // Access values using keys
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;
    std::cout << "Bob's age: " << ageMap["Bob"] << std::endl;

    // Check if a key exists
    if (ageMap.find("Eve") != ageMap.end()) {
        std::cout << "Eve's age: " << ageMap["Eve"] << std::endl;
    } else {
        std::cout << "Eve's age not found." << std::endl;
    }
    print_map(ageMap);
}

#include<set>
template<typename T>
void print_set(const std::set<T>& myset) {
    for(const auto& s : myset) {
        std::cout << s << ",";
    }
    std::cout << std::endl;
}

/*
insert
find
erase
*/
void set_demo() {
    std::set<int> mySet = {1,2,3,4,5}; 
    mySet.insert(6);
    mySet.insert(3);

    // Check if an element exists
    if (mySet.find(4) != mySet.end()) {
        std::cout << "4 exists in the set." << std::endl;
    } else {
        std::cout << "4 does not exist in the set." << std::endl;
    }

    if(mySet.find(10) != mySet.end()){
        std::cout << "10 exists in the set." << std::endl;
    } else {
        std::cout << "10 does not exist in the set." << std::endl;
    }

    mySet.erase(2);

    print_set(mySet);

// Create a set of strings
    std::set<std::string> stringSet;
    stringSet.insert("apple");
    stringSet.insert("banana");
    stringSet.insert("cherry");
    stringSet.insert("apple"); //Duplicate, will not be inserted
    print_set(stringSet);
}


void erase_from_iterator() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(auto it = numbers.begin(); it != numbers.end(); ) {
        if (*it % 2 == 0 ) {
            it = numbers.erase(it);
        } else {
            ++it;
        }
    }
    print_vector(numbers);
}


int main() {
    //stack_demo();

    //list_demo();

    //map_demo();

    //set_demo();

    vector_demo();

    //erase_from_iterator();
}