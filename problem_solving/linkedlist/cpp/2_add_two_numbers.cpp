/*
https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150

add n1, n2 and carry

*/

#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include "../../utils/utils.h"
#include "../../common_header.h"
using namespace std;


ListNode* add_two_numbers(ListNode* a, ListNode* b)  {
    ListNode* result = new ListNode(0);
    auto node = result;
    int carry = 0;
    while(a || b || carry>0) {
        int sum = carry;
        if(a) {
            sum += a->val;
        }
        if (b) {
            sum += b->val;
        }
        int num = sum % 10;
        carry = sum / 10;
        node->next = new ListNode(num);
        node = node->next;
        if(a) {
            a = a->next;
        }
        if(b) {
            b = b->next;
        }
    }   
    ListNode* remaining = a;    
    if (b) {
        remaining = b;
    }
    node->next = remaining;
    return result->next;
}



int main() {
    ListNode* a = new ListNode(2);
    a->next = new ListNode(4);
    a->next->next = new ListNode(3);
    print_linked_list(a);

    ListNode* b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(4);
    print_linked_list(b);

    auto result = add_two_numbers(a, b);
    std::cout << "result: ";
    print_linked_list(result);

    //case II
    a = new ListNode(0);
    print_linked_list(a);

    b = new ListNode(0);
    print_linked_list(b);

    result = add_two_numbers(a, b);
    std::cout << "result: ";
    print_linked_list(result);

    //case III
    a = new ListNode(9);
    a->next = new ListNode(9);
    a->next->next = new ListNode(9);
    a->next->next->next = new ListNode(9);
    a->next->next->next->next = new ListNode(9);
    a->next->next->next->next->next = new ListNode(9);
    a->next->next->next->next->next->next = new ListNode(9);
    print_linked_list(a);

    b = new ListNode(9);
    b->next = new ListNode(9);
    b->next->next = new ListNode(9);
    b->next->next->next = new ListNode(9);
    print_linked_list(b);

    result = add_two_numbers(a, b);
    std::cout << "result: ";
    print_linked_list(result);
}

