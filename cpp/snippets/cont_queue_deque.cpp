/**
 queue ~ well known Q that we have in real life... FIFO
    push
    pop
    size
    empty
    front()
    back()

 deque: insertion/deletion at both ends allowed, random access allowed
    push_back / front
    pop_back / front
    empty
    size
    []
    front
    back
    insert, erase
 */

#include <queue>
#include<iostream>

void queue_demo() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    while (!q.empty()) {
        std::cout << "front: " << q.front() << " back: " << q.back() << std::endl;
        q.pop();
    };
}


#include <deque>
void deque_demo() {
    std::deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(31);
    dq.push_front(32);

    std::cout << "front: " << dq.front() << " back: " << dq.back() << std::endl;
    dq.pop_back();
    std::cout << "front: " << dq.front() << " back: " << dq.back() << std::endl;
    dq.pop_front();
    std::cout << "front: " << dq.front() << " back: " << dq.back() << std::endl;

    for (auto elem : dq) {
        std::cout << elem << ",";
    }
    std::cout << std::endl;
}


int main() {
    //queue_demo();

    deque_demo();

    return 0;
}