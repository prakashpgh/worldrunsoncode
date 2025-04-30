#include <vector>
#include <iostream>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>

template<typename T>
void print_vector(const std::vector<T>& vec) {
    for(auto v : vec) {
        std::cout << v << ",";
    }
    std::cout << std::endl;
    return;
}

template<typename T>
void print_vector_of_vector(const std::vector<std::vector<T>>& vec) {
    for(auto v : vec) {
        for( auto elem : v) {
            std::cout << elem << ",";
        }
        std::cout << std::endl;    
    }
    
    return;
}




#include<array>
template<typename T>
void print_std_array(const std::array<T,20>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;
}




void print_array(const int arr[], size_t size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;
}



template<typename K, typename V>
void print_map(const std::map<K, V>& my_map) {
    for(const auto& pair : my_map) {
        std::cout << pair.first << "=>" << pair.second << std::endl;
    }
}



template<typename K, typename V>
void print_unordered_map(const std::unordered_map<K, V>& my_map) {
    for(const auto& pair : my_map) {
        std::cout << pair.first << "=>" << pair.second << std::endl;
    }
}


template<typename K, typename V>
void print_multi_map(const std::multimap<K, V>& my_map) {
    for(const auto& pair : my_map) {
        std::cout << pair.first << "=>" << pair.second << std::endl;
    }
}

template<typename T>
void print_unordered_set(const std::unordered_set<T>& myset) {
    for(const auto& s : myset) {
        std::cout << s << ",";
    }
    std::cout << std::endl;
}


template<typename T>
void print_set(const std::set<T>& myset) {
    for(const auto& s : myset) {
        std::cout << s << ",";
    }
    std::cout << std::endl;
}

template<typename T>
void print_set(const std::multiset<T>& myset) {
    for(const auto& s : myset) {
        std::cout << s << ",";
    }
    std::cout << std::endl;
}



template<typename T>
void print_list(const std::list<T>&  lst) {
    // Iterate through the list and print elements
    std::cout << "List elements: ";
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;    
}

#include<forward_list>
template<typename T>
void print_fw_list(const std::forward_list<T>&  lst) {
    // Iterate through the list and print elements
    std::cout << "List elements: ";
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;    
}


