/*
'''
flatten_multilevel_double_linklist
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

use of stack to store the next when child node is encountered.
look for node where child is not null
    apply the recursive to the child

    set up links between current and the child.. next and prev
    set up links between saved next and the child tail.

O(N)
O(1)
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


Node* flatten(Node* head) {
    if(!head) {
        return nullptr;
    }
    Node* node = head;
    std::stack<Node*> st;

    while(node || !st.empty()) {
        if(node && node->child) {
            //if there is a child node
            if(node->next) {
                st.push(node->next); //push to stack.
            }
            node->next = node->child;//go to the child node.
            node->child->prev = node;
            node->child = nullptr;
        } 
        if(!node->next && !st.empty()) {
            //we are at the end of the list,,. check stack.
            auto next_node = st.top();
            st.pop();
            if(next_node) {
                node->next = next_node;
                next_node->prev = node;
            }
        }
        node = node->next;
    }
    return head;
}

int main() {
    return 0;
}


    


