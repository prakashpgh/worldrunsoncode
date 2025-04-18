#include<list>
#include<iostream>
#include "../utils/utils.h"

/*
list => double LL
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
    std::list<int> myList = {1, 2, 3, 4, 5};//elements are added in the order..

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
    myList.erase(++myList.begin());
    print_list(myList);
    

    if(myList.empty()) {
        std::cout << "list is empty" << std::endl;
    } else {
        std::cout << "size: " << myList.size() << std::endl;
    }


}

#include<forward_list>
void forward_list_demo() {
    std::forward_list<int> myForwardList = {1, 2, 3, 4, 5};
    std::cout << "front: " << myForwardList.front() << std::endl;

    print_fw_list(myForwardList);

    myForwardList.pop_front();
    std::cout << "front: " << myForwardList.front() << std::endl;

    auto it = myForwardList.begin();
    std::advance(it, 2);
    myForwardList.insert_after(it, 100);
    print_fw_list(myForwardList);

    myForwardList.insert_after(myForwardList.before_begin(), 0);
    print_fw_list(myForwardList);

    std::cout << "erasing..." << std::endl;
    myForwardList.erase_after(it);
    print_fw_list(myForwardList);
    std::cout << "after erasing..." << std::endl;


}



int main() {
     //list_demo();

     forward_list_demo();
}