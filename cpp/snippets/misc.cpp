#include<ctime>
#include<iostream>
#include<cstdlib>

void test_random() {
    srand(time(0));
    int random = rand();
    std::cout << random << std::endl;

    int ranged_num = rand() % 100 + 1;
    std::cout << ranged_num << std::endl;
}

//gcd
#include<numeric>
void test_gcd() {
    int g = std::gcd(12, 16);
    std::cout << "gcd: " << g << std::endl;
}

//min & max
void test_min_max() {
    int i = INT_MIN;
    i = INT_MAX;
    
}
///////////////////////////////////////////////////////////////////////////////////
//three way comparison operator

#include <iostream>
#include <compare> // For std::strong_ordering, std::weak_ordering, etc.

class Point {
public:
    int x;
    int y;

    constexpr Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

    // Define the spaceship operator
    constexpr auto operator<=>(const Point& other) const = default;

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

void spaceship_operator() {
    Point p1(1, 2);
    Point p2(1, 2);
    Point p3(3, 4);

    std::cout << "p1 == p2: " << (p1 == p2) << std::endl;
    std::cout << "p1 < p3: " << (p1 < p3) << std::endl;
    std::cout << "p1 > p3: " << (p1 > p3) << std::endl;
    std::cout << "p1 <= p2: " << (p1 <= p2) << std::endl;
    std::cout << "p1 >= p3: " << (p1 >= p3) << std::endl;
    std::cout << "p1 != p3: " << (p1 != p3) << std::endl;

    return 0;
}

////////////////////custom comparator

#include <iostream>
#include <compare>

class Circle {
public:
    double radius;

    constexpr Circle(double r = 0.0) : radius(r) {}

    // Custom spaceship operator based on radius
    constexpr auto operator<=>(const Circle& other) const {
        if (radius < other.radius) {
            return std::strong_ordering::less;
        } else if (radius > other.radius) {
            return std::strong_ordering::greater;
        } else {
            return std::strong_ordering::equal;
        }
    }
};

void custom_space_operator() {
    Circle c1(5.0);
    Circle c2(5.0);
    Circle c3(7.0);

    std::cout << "c1 == c2: " << (c1 == c2) << std::endl;
    std::cout << "c1 < c3: " << (c1 < c3) << std::endl;

    return 0;
}



int main() {
    test_random();

    test_gcd();
}