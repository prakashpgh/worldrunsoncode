/*
enum class

    1) strongly typed
    2) scoped enumerators
            enum Color { RED, GREEN, BLUE }; // Traditional enum
            enum TrafficLight { RED, YELLOW, GREEN }; // Collision with Color::RED

            enum class ScopedColor { Red, Green, Blue };
            enum class ScopedTrafficLight { Red, Yellow, Green }; // No collision
    3) explicit underlyling type
        enum class StatusCode : short {
        Success = 200,
        NotFound = 404,
        ServerError = 500
    };

    static_assert(sizeof(StatusCode) == sizeof(short), "StatusCode should have the size of short");
    */


enum class Color { Red, Green, Blue };
enum class Fruit { Apple, Banana, Orange };

void enum_demo() {
    Color myColor = Color::Red;
    Fruit myFruit = Fruit::Apple;

    // Error: Implicit conversion from Color to int is not allowed
    // int colorCode = myColor;

    // Error: Implicit comparison between different enum classes is not allowed
    // if (myColor == myFruit) { ... }

    // You need an explicit cast if you want to convert to an integer
    int colorCode = static_cast<int>(myColor); // colorCode will be 0
}

