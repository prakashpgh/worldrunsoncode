/*
std::stack
push

top 
pop
    top and then pop

size()

increasing or decreasing order
to find the next greater or smaller element in an array

for new addition of num to stack,
    check num > current peek,
    if not, keep poping from the stack, till peek < num
    append num

for increasing, its a good idea to start from the end of the array.
    
*/

#include <stack>
#include<iostream>
using namespace std;

void stack_demo() {
    std::stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    std::cout << "top: " << st.top() << std::endl;
    std::cout << "size: " << st.size() << std::endl;
    while(!st.empty()) {
        std::cout << "top: " << st.top() << std::endl;
        st.pop();
        std::cout << "size after pop: " << st.size() << std::endl;
    }

    //point stack
    struct Point {
        int x;
        int y;
    };

    std::stack<Point> points;
    points.push({1,2});
    points.push({3,4});
    points.push({4,5});

    while (!points.empty()) {
        auto top = points.top();
        std::cout << "[" << top.x << "," << top.y << "]" << std::endl;
        points.pop();
    }
}



int main() {
    stack_demo();
}

