/*
https://leetcode.com/problems/linked-list-cycle/

if no node or only one node, then no cycle.
    
O(n)
*/
#include<iostream>
#include "../../utils/utils.h"
#include "../../common_header.h"
using namespace std;


bool has_cycle(ListNode* head) {
    //no node or only one node
    if(!head or !(head->next)) {
        return false;
    }
    auto slow = head;
    auto fast = head;
    while(slow != fast) {
        if(!fast) {
            return false;
        }
        slow = slow->next;
        fast = fast->next;
        if(fast) {
            fast = fast->next;
        }
    }
    return true;
}


int main() {
    ListNode* a = new ListNode(3);
    a->next = new ListNode(2);
    a->next->next = new ListNode(0);
    a->next->next->next = new ListNode(4);
    a->next->next->next->next = a->next;
    bool result = has_cycle(a);
    std::cout << "result: " << result << std::endl;

    a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = a;
    result = has_cycle(a);
    std::cout << "result: " << result << std::endl;

    a = new ListNode(1);
    result = has_cycle(a);
    std::cout << "result: " << result << std::endl;

    a = new ListNode(1);
    a->next = new ListNode(2);
    a->next->next = new ListNode(3);
    a->next->next->next = new ListNode(4);
    a->next = a;
    bool result = has_cycle(a);
    std::cout << "result: " << result << std::endl;

}

