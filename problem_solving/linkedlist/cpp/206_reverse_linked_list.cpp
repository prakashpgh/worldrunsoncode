/*
'''
https://leetcode.com/problems/reverse-linked-list/

save the next as next
next = prev
prev = node
node = next
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


ListNode* reverse_ll(ListNode* head) {
    auto node = head;
    ListNode* prev = nullptr;
    while(node) {
        auto next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}


int main() {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = new ListNode(5);
    print_linked_list(a);

    auto result = reverse_ll(a);
    print_linked_list(result);
    return 0;
}
