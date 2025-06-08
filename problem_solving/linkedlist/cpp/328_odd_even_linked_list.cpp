/*
https://leetcode.com/problems/odd-even-linked-list/
328_odd_even_linked_list.py
get the even nodes.. 

result should have the odd nodes.. then followed by the even nodes
even_head_node

for each node...
    get the even
    get the odd.
    continue
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


ListNode* odd_even_linked_list(ListNode* head) {
    ListNode* node = head;
    ListNode* odd = new ListNode(0);
    ListNode* even = new ListNode(0);
    auto odd_node = odd;
    auto even_node = even;
    while(node) {
        odd_node->next = node;
        odd_node = odd_node->next;
        node = node->next;

        if(node) {
            even_node->next = node;
            even_node = even_node->next;
            node = node->next;
        }
    }
    even_node->next = nullptr;
    odd_node->next = even->next;
    return odd->next;
}


int main() {
    //#head = [1,2,3,4,5]
    //#Output: [1,3,5,2,4]
    ListNode* A = new ListNode(1);
    ListNode* B = new ListNode(2);
    ListNode* C = new ListNode(3);
    ListNode* D = new ListNode(4);
    ListNode* E = new ListNode(5);
    
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    print_linked_list(A);
    auto result = odd_even_linked_list(A);
    print_linked_list(result);
    
    
    //#head = [2,1,3,5,6,4,7]
    //#Output: [2,3,6,7,1,5,4]
    
    A = new ListNode(2);
    B = new ListNode(1);
    C = new ListNode(3);
    D = new ListNode(5);
    E = new ListNode(6);
    ListNode* F = new ListNode(4);
    ListNode* G = new ListNode(7);
    
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = F;
    F->next = G;
    
    print_linked_list(A);
    result = odd_even_linked_list(A);
    print_linked_list(result);
}
