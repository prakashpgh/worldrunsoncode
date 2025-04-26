/*
#https://leetcode.com/problems/min-stack/
'''
idea is to have another stack... which keeps the minimum..
if the next push is not the min.  push the latest.
pop... pop as normally
'''

'''
#https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/#approach
    push    2*x - min   ; min=x

    pop     min = 2*min - top

    peek    min > top, min, else top
'''

'''
#its a modified version of stack copy.
    a tuple or sub-list is used to keep the count
*/
//avoids storing the repeated values... by storing the count.
class MinStack_with_tuple{
    private:
    std::stack<int> main_stack;
    std::stack<int> min_stack;

    MinStack_with_tuple() {

    }   
    
    void push(int val) {

    }

    int pop() {

    }

    int top() {

    }

    int get_min() {

    }
};
    


class MinStack {
    private:
    std::stack<int> main_stack;
    std::stack<int> min_stack;

    public:
    MinStack() {

    }   
    
    void push(int val) {
        main_stack.push(val);
        if(min_stack.empty() || min_stack.top() >=  val) {
            min_stack.push(val);
        }
    }

    void pop() {
        if( !main_stack.empty() && !min_stack.empty() && min_stack.top() == main_stack.top() ) {
            min_stack.pop();
        }
        if(!main_stack.empty()) {
            main_stack.pop();
        }
    }

    int top() {
        if(!main_stack.empty()) {
            return main_stack.top();
        } 
        return -1;
    }

    int getMin() {
        if(!min_stack.empty()) {
            return min_stack.top();
        }
        return -1;
    }
};




//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
MinStack min_stack;
min_stack.push(-2);
min_stack.push(0);
min_stack.push(-3);
int min = min_stack.get_min();
std::cout << "min: " + min;

min_stack.pop();
top = min_stack.top();
std::cout << "top: " << top;

min = min_stack.get_min();
std::cout << "min: " + min << std::endl;

//--------------------------------

MinStack_with_tuple min_stack;
min_stack.push(-2);
min_stack.push(0);
min_stack.push(-3);
min = min_stack.get_min();
std::cout << "min: " + min << std::endl;

min_stack.pop();
top = min_stack.top();
std::cout << "top: " <<  top << std::endl;

min = min_stack.get_min();
std::cout << "min: " + min << std::endl;


