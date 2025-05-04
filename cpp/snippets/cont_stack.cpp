/*
std::stack
push

top 
pop
    top and then pop

size()

//Monotonic stacks
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
#include "../utils/utils.h"
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

//smaller to the left..
std::vector<int> monotonic_find_smaller_on_left( const std::vector<int>& arr) {
    std::stack<int> st;
    int len = arr.size();
    std::vector<int> result(len, -1);
    
    for(int i = 0; i < len; ++i) {
        while( !st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            result[i] = arr[st.top()];
        }
        st.push(i);
    }
    return result;
}


//larger to the left..
std:1:vector<int> monotonic_find_larger_on_left( const std::vector<int>& arr) {
    std::stack<int> st;
    int len = arr.size();
    std::vector<int> result(len, -1);
    
    for(int i = 0; i < len; ++i) {
        //ONLY change in sign here
        while( !st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            result[i] = arr[st.top()];
        }
        st.push(i);
    }
    return result;
}



//smaller to the right
std::vector<int> monotonic_find_smaller_on_right( const std::vector<int>& arr) {
    std::stack<int> st;
    int len = arr.size();
    std::vector<int> result(len, -1);
    
    for(int i = len-1; i >= 0; --i) {
        while( !st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            result[i] = arr[st.top()];
        } else {
            //result[i] = INT_MIN;
        }
        st.push(i);
    }
    return result;
}



//larger to the right
std::vector<int> monotonic_find_larger_on_right( const std::vector<int>& arr) {
    std::stack<int> st;
    int len = arr.size();
    std::vector<int> result(len, len);
    
    for(int i = len-1; i >= 0; --i) {
        while( !st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            result[i] = arr[st.top()];
        } else {
            result[i] = INT_MIN;
        }
        st.push(i);
    }
    return result;
}



int main() {
    //stack_demo();

    //monotonic stacks
    std::vector<int> nums = {4,5,2,10,8};
    auto result = monotonic_find_smaller_on_left(nums);    
    print_vector(result);

    std::cout << "largest to left" << std::endl;
    result = monotonic_find_larger_on_left(nums);    
    print_vector(result);


    std::cout << "smaller to right" << std::endl;
    result = monotonic_find_smaller_on_right(nums);    
    print_vector(result);


    std::cout << "largest to right" << std::endl;
    result = monotonic_find_larger_on_right(nums);    
    print_vector(result);

    std::cout << "next: " << std::endl;
    nums = { 11, 13, 21, 3 };
    result = monotonic_find_larger_on_right(nums);    
    print_vector(result);

}

