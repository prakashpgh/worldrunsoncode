#include <iostream>

/*
constructor

destructor
    virtual destructor
    we need a virtual destructor, else the derived class destructor is not called.. in case of polymorphic.

    delete [] => delete array

copy constructor

assignment operator

move copy constructor

= delete

friend function:
    function which has access to all the members of a class including private members


this => pointer to self
*/


class Animal {
    public:
    Animal(int i) : id(i) {
        std::cout << "Animal constructor: " << id << std::endl;
    }


    //virtual destructor
    virtual ~Animal() {
        std::cout << "Animal destructor " << std::endl;
    }

    int id;
};


class Monkey : public Animal{
    public:
    Monkey(int id) : Animal(id) {
        std::cout << "Monkey constructor " << this->id << std::endl;
    }

    ~Monkey() {
        std::cout << "Monkey destructor " << std::endl;
    }
};

//-----------



int main() {
    Animal animal(5);
    std::cout << "id: " << animal.id << std::endl;

    Monkey m(4);
    std::cout << "id: " << m.id << std::endl;

    {
        std::cout << "strart polymorphic..."  << std::endl;
        Animal* a = new Monkey(6);
        delete a;
        std::cout << "end polymorphic..."  << std::endl;
    }


    //delete []
    int* p_i = new int[8];
    delete [] p_i;
}