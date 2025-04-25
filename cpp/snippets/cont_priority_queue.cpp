/*
priority_queue

    push
        top
        pop
    empty()

    custom compare
        1) bool operator<(const A& a, const A& b)
        2) lambda => 

    by default, its a max heap
    min heap => std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    auto compare = [] (const Person& p1, const Person& p2) { return p1.age > p2.age;};
    std::priority_queue<Person, std::vector<Person>, decltype(compare)> pq_lambda(compare);
*/

#include<queue>
#include<iostream>

void priority_q() {
    std::priority_queue<int> max_heap;
    max_heap.push(10);
    max_heap.push(30);
    max_heap.push(20);
    max_heap.push(5);
    max_heap.push(1);
    while(!max_heap.empty()) {
        std::cout << max_heap.top() << "    ";
        max_heap.pop();
    }
    std::cout << std::endl;

    //min heap....
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    min_heap.push(10);
    min_heap.push(30);
    min_heap.push(20);
    min_heap.push(5);
    min_heap.push(1);
    while(!min_heap.empty()) {
        std::cout << min_heap.top() << "    ";
        min_heap.pop();
    }
    std::cout << std::endl;

    //custom sort...
    struct Person {
        public:
        std::string name;
        int age;
        Person(const std::string& name, int age) : name(name), age(age) {
        }

        bool operator<(const Person& other) const {
            return age < other.age;
        }
    };
    std::priority_queue<Person> pq;
    pq.push({"Alice", 30});
    pq.push({"Bob", 25});
    pq.push({"Charlie", 35});
    while (!pq.empty()) {
        Person p = pq.top();
        std::cout << p.name << "    " << p.age << std::endl;
        pq.pop();
    }
    std::cout << std::endl;

    //using lambda
    auto compare = [] (const Person& p1, const Person& p2) { return p1.age > p2.age;};
    std::priority_queue<Person, std::vector<Person>, decltype(compare)> pq_lambda(compare);
    pq_lambda.push({"Alice", 30});
    pq_lambda.push({"Bob", 25});
    pq_lambda.push({"Charlie", 35});
    while (!pq_lambda.empty()) {
         Person p = pq_lambda.top();
         std::cout << p.name << "    " << p.age << std::endl;
         pq_lambda.pop();
    }
    std::cout << std::endl;


}


int main() {
    priority_q();
    return 0;
}