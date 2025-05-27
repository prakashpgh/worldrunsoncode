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
numbers.erase(std::remove_if( numbers.begin(), numbers.end(), [] (int n) {return n%2 == 0;}), numbers.end());
Or
it = numbers.erase(it);
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
/*
remove_if => moves the elements which are to be kept at the beginning of the iterator, 
   and adds the elements that are to be deleted at the end of the iterator.
   the return iterator => beginning of the elements that are to be deleted.
*/
void remove_from_iterator_2() {
   std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   for (int n : numbers ) {
      std::cout << n << "  ";
   }
   auto new_end = std::remove_if( numbers.begin(), numbers.end(), [] (int n) {return n%2 == 0;});

   std::cout << "after...";
   for (auto it = numbers.begin(); it != new_end; ++it) {
      std::cout << *it << " ";
   }

   numbers.erase(new_end, numbers.end());

   std::cout << "after remove...";
   for (int n : numbers ) {
      std::cout << n << "  ";
   }
}

//implementation of std::remove_if
template <typename ForwardIterator, typename UnaryPredicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
    ForwardIterator result = first;
    for (; first != last; ++first) {
        if (!pred(*first)) {
            if (result != first) {
                std::swap(*result, *first);
            }
            ++result;
        }
    }
    return result;
}

/*
++it => better option

it++ => 
1) Creating a temporary copy of the iterator's current state.
2) Incrementing the original iterator.
3) Returning the temporary copy.
*/



 int main() {
   remove_from_iterator();

   remove_from_iterator_2();
 }