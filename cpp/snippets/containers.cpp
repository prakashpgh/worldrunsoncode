/**
    std::advance() => does both forward or backward advance..
    std::prev
    std::next

*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
#include "../utils/utils.h"

void iterators() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};
    std::list<int> myList = {10, 20, 30, 40, 50};
    
    auto iter = myVector.begin();
    std::advance( iter, 2);
    std::cout << "Element after +2: " << *iter << std::endl; 

    std::advance( iter, -2);
    std::cout << "Element after -2: " << *iter << std::endl; 

    int distance = std::distance(myVector.begin(), iter);
    std::cout << "distance: " << distance << std::endl; 

    for(auto it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << ","; 
    }
    std::cout << std::endl;

    //cbegin
    for(auto it = myVector.cbegin(); it != myVector.cend(); ++it) {
        std::cout << *it << ","; 
    }
    std::cout << std::endl;

    //rbegin
    for(auto it = myVector.rbegin(); it != myVector.rend(); ++it) {
        std::cout << *it << ","; 
    }
    std::cout << std::endl;

    //crbegin
    for(auto it = myVector.crbegin(); it != myVector.crend(); ++it) {
        std::cout << *it << ","; 
    }
    std::cout << std::endl;

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



//std::tuple

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

/*
ranges used to filter and transform sequences
*/
void ranges_demo() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto even_numbers = numbers 
                        | std::views::filter([](int n) { return n % 2 == 0; })
                        | std::views::transform([](int n) { return n * n; });

    for (int n : even_numbers) {
        std::cout << n << " ";
    }

}



int main() {
    //stack_demo();

    //list_demo();

    //map_demo();

    //set_demo();

    //vector_demo();

    

    //copy_vector();

    //erase_from_iterator();
    iterators();
}



/*
stack.push

stack.top
stack.pop

------------------
q	
push
front
pop

---
dq

push_back
push_front
pop_back
pop_front
front
back
----------------
priority_queue

push
top
pop

-----------------
map
[]
insert(std::make_pair())
find()

====
set
	insert
	find
	erase
===================
list
	push_back
	push_front
	pop_front
	pop_back

	front
	back

*/

/*

Feature	            std::deque	                                        std::list

Underlying	        Discontiguous fixed-size arrays (chunks)	        Doubly-linked list  ******        
                    (no resizing of existing chunks)

Random Access	    Efficient, O(1)	Inefficient,                        O(n)                ******

Insert/Delete End	Efficient, O(1) amortized	Efficient,              O(1)

Insert/Delete Mid	Inefficient, O(n)	Efficient,                      O(1) (given an iterator)    ******

Iterator Validity	Can be invalidated on middle insertion/deletion	    Generally remains valid on insertion/deletion   **********

Cache Locality	    Better	                                            Worse                   ********

Memory Overhead	    Potentially larger minimum	                        Overhead per element (pointers)    **** 

*/


/*
low latency, high throughput system

1) efficient algorithms & data structure
        cache friendly ds

2) multi-threading.
    do all the work in separate thread
    thread pool

    Effective threading: use the right number of threads
    
    lock free/ low contention ds

3) DB connection pooling

4) caching.
    caching of reference data

5) load balancing

6) Message Q




*/