/*'''
https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

find the middle head using fast and slow pointers
delete the node
'''
*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


ListNode* delete_middle_node(ListNode* head) {
    ListNode* result = nullptr;
    if(!head) {
        return nullptr;
    }
    if(head->next == nullptr) {
        return nullptr;
    }

    ListNode* dummy = new ListNode(0); // Create a dummy node with a dummy value
    dummy->next = head;

    ListNode* slow = dummy;
    ListNode* fast = head;
    while(fast != nullptr  && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    //middle node
    auto node_to_delete = slow->next;
    slow->next = node_to_delete->next;
    delete node_to_delete;
    node_to_delete = nullptr;

    auto new_head = dummy->next;
    delete dummy;
    dummy = nullptr;

    return new_head;
}

int main() {
    //#head = [1,3,4,7,1,2,6]
    //#Output: [1,3,4,1,2,6]
    ListNode* A = new ListNode(1);
    ListNode* B = new ListNode(3);
    ListNode* C = new ListNode(4);
    ListNode* D = new ListNode(7);
    ListNode* E = new ListNode(1);
    ListNode* F = new ListNode(2);
    ListNode* G = new ListNode(6);
    
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = F;
    F->next = G;
    
    print_linked_list(A);
    auto result = delete_middle_node(A);
    print_linked_list(result);
    
    A = new ListNode(1);
    B = new ListNode(2);
    C = new ListNode(3);
    D = new ListNode(4);
    
    A->next = B;
    B->next = C;
    C->next = D;
    //#head = [1,2,3,4]
    //#Output: [1,2,4]
    print_linked_list(A);
    result = delete_middle_node(A);
    print_linked_list(result);
    
    
    
    A = new ListNode(2);
    B = new ListNode(1);
    A->next = B;
    //#head = [2,1]
    //#Output: [2]
    print_linked_list(A);
    result = delete_middle_node(A);
    print_linked_list(result);
    

    A = new ListNode(1);
    //#head = [1]
    //#Output: []
    print_linked_list(A);
    result = delete_middle_node(A);
    print_linked_list(result);
}

