/*
    auto tup = std::make_tuple("test", 2);
    //get
    int i = std::get<1>(tup);
    //[]
    auto [x,y] = tup;
*/
#include <iostream>
#include <tuple>
#include <string>
using namespace std;

void cplus_version() {
if (__cplusplus == 202302L) std::cout << "C++23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";    
}


int main() {
    cplus_version();
    

    std::tuple<int, std::string, double> myTuple(10, "Hello", 3.14);
    auto myOtherTuple = make_tuple(20, "World", 2.71);
    // Using tie to unpack tuples
    int intValue;
    std::string stringValue;
    double doubleValue;

    std::tie(intValue, stringValue, doubleValue) = myTuple;    
    cout << "Int value: " << intValue << endl;
    cout << "String value: " << stringValue << endl;
    cout << "Double value: " << doubleValue << endl;

    int firstElement = std::get<0>(myTuple);
    std::string secondElement = std::get<1>(myTuple);
    double thirdElement = std::get<2>(myTuple);
    std::cout << "First element: " << firstElement << std::endl;
    std::cout << "Second element: " << secondElement << std::endl;
    std::cout << "Third element: " << thirdElement << std::endl;


    auto [x,y,z] = myTuple;
    cout << "structured binding x: " << x << endl;
    cout << "structured binding y: " << y << endl;
    cout << "structured binding z: " << z << endl;

    //
    // Tuple comparison
    tuple<int, string> tuple1(1, "apple");
    tuple<int, string> tuple2(1, "apple");
    tuple<int, string> tuple3(2, "banana");

    if (tuple1 == tuple2) {
        cout << "tuple1 and tuple2 are equal" << endl;
    } else {
        cout << "tuple1 and tuple2 are not equal" << endl;
    }

    if (tuple1 < tuple3) {
        cout << "tuple1 is less than tuple3" << endl;
    } else {
        cout << "tuple1 is not less than tuple3" << endl;
    }


   return 0; // Indicate success
}