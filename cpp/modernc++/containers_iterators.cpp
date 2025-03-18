/**
 std::vector emplace_back & push_back difference, 
    push_back constructor and copy/move constructor
    emplace_back only constructor
--
removing while iterating
   if (*it % 2 ==0) {
         it = numbers.erase(it);  => returns the next one
      } else {
         ++it;
      }

--
std::array

--
std::deque

 */

#include<vector>
#include<iostream>
#include<algorithm>

class Test {
   public:
   Test() {
      std::cout << "Test" << std::endl;
   }

   Test(const Test&) {
      std::cout << "Test" << std::endl;
   }

   
   int i;
};

//removing an item from an iterator
void remove_from_iterator() {
   std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   for (int n : numbers ) {
      std::cout << n << "  ";
   }

   for (auto it = numbers.begin(); it != numbers.end();) {
      if (*it % 2 ==0) {
         it = numbers.erase(it);
      } else {
         ++it;
      }
   }
   std::cout << "after remove...";
   for (int n : numbers ) {
      std::cout << n << "  ";
   }
}

//more efficient and recommended method
void remove_from_iterator_2() {
   std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   for (int n : numbers ) {
      std::cout << n << "  ";
   }

   numbers.erase(std::remove_if( numbers.begin(), numbers.end(), [] (int n) {return n%2 == 0;}), numbers.end());

   std::cout << "after remove...";
   for (int n : numbers ) {
      std::cout << n << "  ";
   }
}



 int main() {
   remove_from_iterator();

   remove_from_iterator_2();
 }