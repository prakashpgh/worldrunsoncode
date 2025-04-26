/*
'''
https://leetcode.com/problems/lru-cache/

for storing the values, we use dictionary.  key,Node

so the dictionary has key = key, value = actual Q-node.
Q-node = has key + value. 
    it cleans the cache as required if over-capacity, and using the key, cleans the dictionary


    get() => remove and add to refresh the cache Q
    put() => check for the length... of queue, remove elements if necessary.... 
             add new data

dictionary => we use for quick access and put.
deque => we use for maintaining the cache, removing from dictionary is not possible easily.

             
for maintaining LrU, we use a de-queue
    methods
        add(Node)
        remove(Node)
'''

{
    std::list<std::pair<int, int>> cache;
    std::unordered_map<int, std::list<std::pair<int, int>::iterator >> map;
}


*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


class QNode {
    public:
    QNode(int key, int value) : key(key), 
                                value(value),
                                prev(nullptr),
                                next(nullptr) 
    { }
    int value;
    int key;
    QNode* prev;
    QNode* next;
};


class LRUCache {
private:
    int capacity;
    QNode* head;
    QNode* tail;
    std::unordered_map<int, QNode*> map;

    void remove_node(QNode* node) {
        auto prev = node->prev;
        auto next = node->next;
        if(prev)
            prev->next = next;
        if (next)
            next->prev = prev;
        if(node == head) 
            head = next;
        if (node == tail)
            tail = prev;
        node->next = nullptr;
        node->prev = nullptr;
    }

    void add_to_front(QNode* node) {
        if(!head) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    } 

    void remove_from_tail() {
        if(tail) {
            auto itr = map.find(tail->key);
            if(itr != map.end()) {
                map.erase(itr);
                std::cout << "deleted from the map: " << tail->key << std::endl;
            }

            auto prev = tail->prev;
            if(head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                delete tail;
                tail = prev;
                if(tail) {
                    tail->next = nullptr;
                } else {
                    head = nullptr;
                }
            }
        }
    }

public:
    LRUCache(int capacity) : capacity(capacity), 
                            head(nullptr), 
                            tail(nullptr) {
    }

    int get(int key)  {
        if(map.find(key) != map.end()) {
            auto node = map[key];
            remove_node(node);
            add_to_front(node);
            return node->value;
        }
        return -1;
    }


    void put(int key, int value) {
        if( map.find(key) != map.end() ) {
            //already exists.
            auto node = map[key];
            node->value = value;
            //
            remove_node(node);
            add_to_front(node);
        }
        else {
            if(map.size() == capacity)  {
                remove_from_tail();
            }
            if(map.size() < capacity ) {
                QNode* node = new QNode(key, value);
                add_to_front(node);
                map[key] = node;
            }
        }
    }
};


class LRUCache2 {
private:
    int capacity;
    std::list<std::pair<int, int>> cacheList; // Stores {key, value} pairs
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

    void moveToFront(int key) {
        auto it = cacheMap[key];
        std::pair<int, int> kv = *it; // copy the key value pair.
        cacheList.erase(it);
        cacheList.push_front(kv);
        cacheMap[key] = cacheList.begin();
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        moveToFront(key);
        return cacheList.front().second;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            moveToFront(key);
            cacheList.front().second = value;
        } else {
            if (cacheList.size() == capacity) {
                int lruKey = cacheList.back().first;
                cacheMap.erase(lruKey);
                cacheList.pop_back();
            }
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        }
    }
};



#include <cassert>

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    assert(lru.get(1) == 1);
    lru.put(3, 3);
    assert(lru.get(2) == -1);
    lru.put(4, 4);
    assert(lru.get(1) == -1);
    assert(lru.get(3) == 3);
    assert(lru.get(4) == 4);
    std::cout << "\n--- T1 passed ---" << std::endl;

    std::cout << "\n--- More Test Cases ---" << std::endl;
    LRUCache lru2(3);
    lru2.put(1, 1);
    lru2.put(2, 2);
    lru2.put(3, 3);
    assert(lru2.get(1) == 1);
    lru2.put(4, 4);
    assert(lru2.get(2) == -1);
    assert(lru2.get(4) == 4);
    assert(lru2.get(3) == 3);
    std::cout << "\n--- T2 passed ---" << std::endl;

    LRUCache lru3(1);
    lru3.put(1, 1);
    assert(lru3.get(1) == 1);
    lru3.put(2, 2);
    assert(lru3.get(1) == -1);
    assert(lru3.get(2) == 2);
    std::cout << "\n--- T3 passed ---" << std::endl;

    LRUCache lru4(0);
    lru4.put(1, 1);
    assert(lru4.get(1) == -1);
    lru4.put(2, 2);
    assert(lru4.get(2) == -1);
    std::cout << "\n--- T4 passed ---" << std::endl;

    std::cout << "All test cases passed!" << std::endl; // Added this line

    return 0;
}