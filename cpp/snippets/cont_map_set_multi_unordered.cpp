/*
Summary Table:

Container	    Ordered?	Duplicates?	Implementation	Average Time Complexity (Insertion, Deletion, Lookup)
set	            Yes	        No	        Binary Tree	    O(log n)
map	            Yes	        No	        Binary Tree	    O(log n)
multiset	    Yes	        Yes	        Binary Tree	    O(log n)
multimap	    Yes	        Yes	        Binary Tree	    O(log n)
unordered_set	No	        No	        Hash Table	    O(1)
unordered_map	No	        No	        Hash Table	    O(1)
unordered_multiset	No	    Yes	        Hash Table	    O(1)
unordered_multimap	No	    Yes	        Hash Table	    O(1)

set
    insert
    find
        no duplicate entry
    ordered
    no dupes
    self balancing binary trees red-black trees
    O(log N)

multiset
    count
    
    allows duplicate entry
    ordered
    self balancing binary trees red-black trees
    O(log N)

map
    [key]=value
    insert(std::pair<k,v>(k,v));
    ageMap.insert(std::make_pair("David", 28)); // Another way to insert
    []
    find()
        duplicate key not allowed
    self balancing binary trees red-black trees
    O(log N)
    ordered
    no dupes


multimap
    [] operator not provided.
     range()
        duplicate key allowed
    allows duplicate entry
    ordered
    self balancing binary trees red-black trees
    O(log N)


unordered_set
    stored as hashtable.
    better peformance
    O(1)

unordered_multiset

unordered_map
    uses hashtable
    O(1)
unordered_multimap
*/
#include<map>
#include<set>
#include<string>
#include "../utils/utils.h"
#include<iostream>
#include <unordered_map>

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
    //ageMap.insert("David1", 28)); // Another way to insert

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

    //iterating map
    std::unordered_map<int, int> scores_playerid_map;
    scores_playerid_map[1] = 10;
    scores_playerid_map[2] = 20;
    scores_playerid_map[3] = 30;

    for(const auto& [id, player] : scores_playerid_map) {
        std::cout << "id: " << id << " player: " << player << std::endl;
    }


}


void multi_map_demo() {
    std::multimap<std::string, int> ageMap;
    // Insert key-value pairs into the map
    ageMap.insert({"Alice",30});
    ageMap.insert({"Bob",25});
    ageMap.insert({"Charlie",35});
    ageMap.insert({"Charlie",45});
    ageMap.insert({"Charlie",55});
    ageMap.insert(std::make_pair("David", 28)); // Another way to insert

    // Access values using keys
    //std::cout << "Alice's age: " << (ageMap.equal_range("Alice")).first << std::endl;
    //std::cout << "Bob's age: " << ageMap["Bob"] << std::endl;
    auto range = ageMap.equal_range("Charlie");
    for(auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << "     " << it->second << std::endl;
    }
    // Check if a key exists
    if (ageMap.find("Charlie") != ageMap.end()) {
        std::cout << "Charlie's age: " << std::endl;
    } else {
        std::cout << "Charlie's age not found." << std::endl;
    }
    print_multi_map(ageMap);
}


#include<set>

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



void multi_set_demo() {
    std::multiset<int> mySet = {1,2,3,4,5}; 
    mySet.insert(6);
    mySet.insert(6);
    mySet.insert(6);
    mySet.insert(3);
    std::cout << "count of 6: " << mySet.count(6) << std::endl;
    print_set(mySet);
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

#include <unordered_set>
void unordered_set_demo() {

}

#include<algorithm>
void max_element_values() {
    std::map<std::string, int> myMap = {
        {"apple", 10},
        {"banana", 25},
        {"cherry", 15},
        {"date", 20}
    };

    auto mx = std::max_element(myMap.begin(), myMap.end(), [] (const auto& a, const auto& b) {
        return a.second < b.second;
    });

    std::cout << "max in the values: " << mx->second << std::endl;
    std::cout << "max in the values: " << mx->first << std::endl;
}



int main() {
    map_demo();

    //set_demo();

    //multi_set_demo();

    //multi_map_demo();

    //max_element_values();
}


//hashmap details
/*
key => hash_function => bucket
good hash function

Array of buckets
buckets
    collisions
        1) separate chaining: ... linked list
        2) open addressing: => probes for next empty bucket.

    Dynamic resizing:
        load factor = n/capacity
        when hashmap becomes too full, the load factor exceeds a certain threshold, 
        the number of buckets is typically increased, to help maintain efficiency of the hash map
        by reducing the likelihood of collisions


*/

/*
Custom hash implementation
    https://en.cppreference.com/w/cpp/utility/hash
    std::hash => can be used to 
    boost::hash_combine



    struct S
{
    std::string first_name;
    std::string last_name;
    bool operator==(const S&) const = default; // since C++20
};
 
// Before C++20.
// bool operator==(const S& lhs, const S& rhs)
// {
//     return lhs.first_name == rhs.first_name && lhs.last_name == rhs.last_name;
// }
 
// Custom hash can be a standalone function object.
struct MyHash
{
    std::size_t operator()(const S& s) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(s.first_name);
        std::size_t h2 = std::hash<std::string>{}(s.last_name);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};
 
// Custom specialization of std::hash can be injected in namespace std.
template<>
struct std::hash<S>
{
    std::size_t operator()(const S& s) const noexcept
    {
        std::size_t h1 = std::hash<std::string>{}(s.first_name);
        std::size_t h2 = std::hash<std::string>{}(s.last_name);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};

 */
