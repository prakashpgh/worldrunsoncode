/*
Max stack implementation with peekMax & posMax

ListNode ~ doubly linked list for the stack..
    push
    pop
    peek
Map key = value, value=vector of node pointers
    map is stored in ascending order.  so you can get the max.. or even the min.
    popMax
    peekMax

    This can be used to implement MinStack as well..
*/
#include<map>
#include<vector>
#include<iostream>

class ListNode {

    public:

    ListNode(int d) 
        : next(nullptr), prev(nullptr), data(d)
    {
    }
    ListNode* next;
    ListNode* prev;
    int data;
};


class MaxStack {
    private:
    ListNode* head;
    std::map<int, std::vector<ListNode*>> mapping;


    public:
    MaxStack() {
        head = new ListNode(0);
    }


    void push(int data) {
        ListNode* next = head->next;
        ListNode* new_node = new ListNode(data);
        new_node->next = next;
        if(next) {
            next->prev = new_node;
        }
        head->next = new_node;
        new_node->prev = head;
        
        mapping[data].push_back(new_node);
    }

    int pop() {
        if(nullptr == head->next) {
            throw "stack is empty";
        }
        ListNode* to_delete = head->next;
        int val = to_delete->data;

        ListNode* next = to_delete->next;
        if(next) {
            next->prev = head;
        }
        head->next = next;

        to_delete->next = nullptr;
        to_delete->prev = nullptr;
        delete to_delete;
        
        //remove from map
        mapping[val].pop_back();
        if(mapping[val].empty()) {
            mapping.erase(val);
        }

        return val;
    }

    int peek() {
        if(nullptr == head->next) {
            throw "stack is empty";
        }
        return head->next->data;
    }

    int popMax() {
        if(mapping.empty()) {
            throw "its empty";
        }
        int val = (*mapping.rbegin()).first;
        ListNode* todelete = (*mapping.rbegin()).second.back();
        ListNode* next = todelete->next;
        ListNode* prev = todelete->prev;
        if(next) {
            next->prev = prev;
        }
        prev->next = next;
        
        (*mapping.rbegin()).second.pop_back();
        if((*mapping.rbegin()).second.empty())  {
            mapping.erase(val);
        }
        return val;
    }

    int peekMax() {
        if(mapping.empty()) {
            throw "its empty";
        }
        return (*mapping.rbegin()).first;
    }

};


int main() {
    MaxStack max_stack;
    max_stack.push(2);
    max_stack.push(4);
    max_stack.push(8);
    max_stack.push(5);
    
    std::cout << "peek: " << max_stack.peek() << std::endl; //5
    std::cout << "peekMax: " << max_stack.peekMax() << std::endl; //8
    
    std::cout << "popMax " << max_stack.popMax() << std::endl;//8

    std::cout << "peek: " << max_stack.peek() << std::endl;//5
    std::cout << "peek: " << max_stack.peekMax() << std::endl;//5
    
    std::cout << "popMax " << max_stack.pop() << std::endl;//5

    std::cout << "peek: " << max_stack.peek() << std::endl;//4
    std::cout << "peek: " << max_stack.peekMax() << std::endl;//4
    
    max_stack.push(10);
    max_stack.push(6);
    std::cout << "peek: " << max_stack.peek() << std::endl;//6
    std::cout << "peek: " << max_stack.peekMax() << std::endl;//10

    return 0;
}