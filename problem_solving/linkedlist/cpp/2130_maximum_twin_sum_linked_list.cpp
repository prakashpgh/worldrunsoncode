/*'''
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
2130_maximum_twin_sum_linked_list.py

Approach I:
iterate the linked list, and store the values in a list.
traverse the list with 2-pointer approach.  find the max. sum pair

t: O(n)
s: O(n)

Approach II:
    find middle using fast and slow pointers
    reverse the second half of the LL
    now traverse the first half and the 2nd half, and find the twin sum.. and max. of twin sum
t: O(n)
s: O(1)

'''*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<stack>


int maximum_twin_sum_linked_list(ListNode* root) {
    int max = INT_MIN;
    ListNode* slow = root;
    ListNode* fast = root;
    ListNode* prev = nullptr;
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast) {
            fast = fast->next;
        }
    }
    ListNode* mid = slow;
    prev->next = nullptr;
    //reverse the 2nd half
    ListNode* rev = nullptr;
    while(mid) {
        auto next = mid->next;
        mid->next = rev;
        rev = mid;
        mid = next;
    }
    ListNode* reverse = rev;

    //
    ListNode* r = reverse;
    ListNode* l = root;
    while(r) {
        int sum = r->val + l->val;
        if( sum > max) {
            max = sum;
        }
        r=r->next;
        l=l->next;
    }
    return max;
}


int main() {
    ListNode* A = new ListNode(5);
    ListNode* B = new ListNode(4);
    ListNode* C = new ListNode(2);
    ListNode* D = new ListNode(1);
    
    A->next = B;
    B->next = C;
    C->next = D;
    //#head = [5,4,2,1]
    //#Output: 6
    int result = maximum_twin_sum_linked_list(A);
    std::cout << "result=" << result << std::endl;
    
    //#-------------------------------
    
    A = new ListNode(4);
    B = new ListNode(2);
    C = new ListNode(2);
    D = new ListNode(3);
    
    A->next = B;
    B->next = C;
    C->next = D;
    
    //#head = [4,2,2,3]
    //#Output: 7
    result = maximum_twin_sum_linked_list(A);
    std::cout << "result=" << result << std::endl;
    
    //#============================
    A = new ListNode(1);
    B = new ListNode(100000);
    
    A->next = B;
    //#head = [1,100000]
    //#Output: 100001
    result = maximum_twin_sum_linked_list(A);
    std::cout << "result=" << result << std::endl;
    
    
}
