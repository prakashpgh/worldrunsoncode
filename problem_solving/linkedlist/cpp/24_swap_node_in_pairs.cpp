/*
https://leetcode.com/problems/swap-nodes-in-pairs/

       
*/

#include<iostream>
#include<tuple>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


std::tuple<ListNode*,ListNode*,ListNode*> reverse(ListNode* head, int k) {
    ListNode* prev = nullptr;
    auto node = head;
    auto new_tail = head;
    ListNode* next_head = nullptr;
    while(node && k > 0) {
        ListNode* next = node->next;
        node->next = prev;
        prev = node;
        node = next;
        next_head = next;
        k -= 1;
    }
    auto new_head = prev;


    return make_tuple(new_head, new_tail, next_head);
}


ListNode* reverse_in_pairs(ListNode* head) {
    ListNode* node = head;
    ListNode* reversed_head = nullptr;
    ListNode* prev_chain_tail = nullptr;
    while(node) {

        auto [new_head, new_tail, next_head] = reverse(node, 2);
        if(prev_chain_tail) {
            prev_chain_tail->next = new_head;
        }
        prev_chain_tail = new_tail;
        if(!reversed_head) {
            reversed_head = new_head;
        }
        node = next_head;
    }

    return reversed_head;
}




int main() {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    a->next->next->next->next->next = new ListNode(6);
    a->next->next->next->next->next->next = new ListNode(7);

    print_linked_list(a);
    auto [new_head, new_tail, next_head] = reverse(a, 2);
    //std::cout << "reverse: " << new_head << std::endl;
    print_linked_list(new_head);

    a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    a->next->next->next->next->next = new ListNode(6);
    a->next->next->next->next->next->next = new ListNode(7);
    print_linked_list(a);
    auto reversed_head = reverse_in_pairs(a);
    print_linked_list(reversed_head);
}