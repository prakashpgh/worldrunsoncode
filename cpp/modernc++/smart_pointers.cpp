/*
unique_ptr  
    single ownership
    movable

shared_ptr  to share between objects/threads
    multiple ownership
    maintains ref counting
    move/copy allowd

weak_ptr    to break cycles or optional references to shared_ptr


 */

 #include<memory>
 #include<iostream>


class Test {
private:
    int _data;
public:
    Test(int data) : _data(data) 
    {
        std::cout << "Test constructor" << std::endl;
    }

    ~Test() 
    {
        std::cout << "Test destructor" << std::endl;
    }
};


void test_unique_ptr() {
   std::unique_ptr<Test> tp = std::make_unique<Test>(3);
   std::unique_ptr<Test> tp2 = std::move(tp);

}

void test_shared_ptr() {
    std::cout << "testing shared_ptr" << std::endl;
    auto sp_1 = std::make_shared<Test>(3);
    std::cout << "use_count: " << sp_1.use_count() << std::endl;
    {
        auto sp_2 = sp_1;
        std::cout << "use_count: " << sp_1.use_count() << std::endl;
    }
    std::cout << "use_count: " << sp_1.use_count() << std::endl;
}


struct Node {
    int _val = 0;
    Node(int val) : _val(val) {
        std::cout << "Node ()" << std::endl;
    }

    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
    ~Node() {
        std::cout << "Node ~" << std::endl;
    }
};


void test_weak_ptr() {
    std::cout << "test_weak_ptr." << std::endl;
    auto p1 = std::make_shared<Node>(2);
    auto p2 = std::make_shared<Node>(3);
    p1->next = p2;
    p2->prev = p1;
    std::cout << "p1 ref.." << p1.use_count() << std::endl;
    std::cout << "p2 ref.." << p2.use_count() << std::endl;
    if (auto locked = p2->prev.lock()) {
        std::cout << "p1 ref.." << p2.use_count() << std::endl;
    }
}



int main() {
    test_unique_ptr();

    test_shared_ptr();

    test_weak_ptr();
}