/*
'''
https://leetcode.com/problems/merge-two-sorted-lists/

our typical merge loop..for both valid lists


#meta
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


ListNode* merge_ll(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(0);
    auto node1 = l1;
    auto node2 = l2;
    auto node_result = result;
    while(node1 && node2) {
        if(node1->val <= node2->val) {
            node_result->next = node1;
            node1 = node1->next;
        } else {
            node_result->next = node2;
            node2 = node2->next;
        }
        node_result = node_result->next;
    }
    if(node1) {
        node_result->next = node1;
    } else {
        node_result->next = node2;
    }
    return result->next;
}


int main() {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(4);
    print_linked_list(a);

    ListNode* a1 = new ListNode(1);
    a1->next = new ListNode(3);
    a1->next->next = new ListNode(4);
    print_linked_list(a1);
    auto result = merge_ll(a, a1);
    print_linked_list(result);
    return 0;
}


