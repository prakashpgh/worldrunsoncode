/*
'''
https://leetcode.com/problems/insert-delete-getrandom-o1/

hashmap/dictionary => insert, remove
                        getRandom is bad.   
                        we will use list to store the keys => key mapping in a list


list    
    hashmap will store value, list-index

    remove => swap with end, 
                remove from end..   
                get index from hashmap, .. 

    insert -> not an issue

    random -> get random.. get the key from the random index, use the key for retrieving from dictionary


'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


class RandomizedSet {
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(nums.find(val) == nums.end()) {
            nums.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(nums.find(val) != nums.end()) {
            nums.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto it = nums.begin();
        std::advance(it, rand() % nums.size());
        return *it;
    }

private:
    std::set<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main() {
    return  0;
}