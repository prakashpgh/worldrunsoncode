#include "../common_header.h"
#include<iostream>


void print_list(ListNode* head) {
    auto node = head;
    while (node) {
        std::cout << node->val << ",";
        node = node->next;
    }
    std::cout << std::endl;
}

ListNode* insert_at_beginning(ListNode* head, int val) {
    auto node = new ListNode(val);
    node->next = head;
    return node;
}

ListNode* insert_at_end(ListNode* head, int val) {
    if (!head) {
        return new ListNode(val); 
    }
    auto node = head;
    while (node->next) {
        node = node->next;
    }
    node->next = new ListNode(val); 
    return head;
}

ListNode* delete_node(ListNode* head, int val) {
    auto node = head;
    ListNode* prev = nullptr;
    if(head == nullptr) {
        return nullptr;
    }
    if(head->val == val) {
        ListNode* new_head = head->next;
        delete head;
        return new_head;
    }
    while(node and node->val != val) {
        prev = node;
        node = node->next;
    }
    if(prev) {
        prev->next = node->next;
        delete node;
    }
    return head;
}


ListNode* reverse_list(ListNode* head) {
    if(!head) {
        return nullptr;
    }
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


ListNode* find_middle_node(ListNode* head) {
    auto node = head;
    auto fast_node = node;
    while(fast_node and fast_node->next) {
        node = node->next;
        fast_node = fast_node->next->next;
    }
    return node;
}


bool has_cycle(ListNode* head) {
    auto slow = head;
    auto fast = slow;
    while(fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) {
            return true;
        }
    }
    return false;
}

ListNode* merge_two_lists(ListNode* l1, ListNode* l2) {
    if (!l1) {
        return l2;
    } 
    if(!l2) {
        return l1;
    }
    ListNode* head = (l1->val < l2->val) ? l1 : l2;
    auto node = head;
    if (head == l1) {
        l1 = l1->next;
    } else {
        l2 = l2->next;
    }

    while(l1 && l2) {
        if(l1->val < l2->val) {
            node->next = l1;
            l1 = l1->next;            
        } else if(l1->val > l2->val) {
            node->next = l2;
            l2 = l2->next;            
        }
        node = node->next;
    }
    if(l1) {
        node->next = l1;
    } else {
        node->next = l2;
    }
    return head;
}

ListNode* create_list(int val, int increment, int times) {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(val);
    auto node = head->next;
    for(int i = 0; i < times; ++i) {
        node->next = new ListNode(node->val + increment);
        node = node->next;
    }
    return head->next;
}


int main() {
    //std::cout << "linked list" << std::endl;
    ListNode* head = new ListNode(3);
    ListNode* A = new ListNode(4);
    ListNode* B = new ListNode(5);
    ListNode* C = new ListNode(6);
    ListNode* D = new ListNode(7);
    head->next = A;
    A->next = B;
    B->next = C;
    C->next = D;
    

    print_list(head);
    auto new_head = insert_at_beginning(head, 10);
    print_list(new_head);

    new_head = insert_at_end(head, 11);
    print_list(new_head);

    std::cout << "after deleteing.." << std::endl;
    new_head = delete_node(new_head,6);
    print_list(new_head);

    std::cout << "after reversing.." << std::endl;
    new_head = reverse_list(new_head);
    print_list(new_head);

    auto middle_node = find_middle_node(new_head);
    std::cout << middle_node->val << std::endl;

    auto cycle = has_cycle(new_head);
    std::cout << cycle << std::endl;

    new_head->next->next = new_head->next;
    cycle = has_cycle(new_head);
    std::cout << cycle << std::endl;

    //merge listsl
    ListNode* odd = create_list(1, 2, 10);
    ListNode* even = create_list(2, 2, 10);
    print_list(odd);
    print_list(even);
    auto result = merge_two_lists(odd, even);
    print_list(result);

}