#include <iostream>
#include <memory>
#include <mutex>

class Singleton {
private:
    // Private constructor to prevent direct instantiation
    Singleton() {
        std::cout << "Singleton created." << std::endl;
        // Initialization code here
    }

    // Prevent copying and moving
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

public:
    // Static method to get the single instance
    static Singleton& getInstance() {
        static Singleton instance; // Thread-safe in C++11 and later
        return instance;
    }

    // Example public method
    void doSomething() const {
        std::cout << "Singleton is doing something." << std::endl;
    }

    // Optional: Method to destroy the instance (if needed in specific scenarios)
    static void destroyInstance() {
        instancePtr.reset();
        std::cout << "Singleton destroyed." << std::endl;
    }

private:
    // Optional: Using a unique_ptr for automatic destruction (thread-safe lazy initialization)
    static std::unique_ptr<Singleton> instancePtr;
    static std::mutex mutex_;
};

/////////////////////Observer

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <memory>

// Forward declaration
class Observer;

// Subject (Observable) Interface
class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// Observer Interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};


// Concrete Subject
class ConcreteSubject : public Subject {
    private:
        std::string state;
        std::list<Observer*> observers; // Using list for efficient removal
    
    public:
        ConcreteSubject(const std::string& initialState) : state(initialState) {}
    
        const std::string& getState() const {
            return state;
        }
    
        void setState(const std::string& newState) {
            state = newState;
            notify();
        }
    
        void attach(Observer* observer) override {
            observers.push_back(observer);
        }
    
        void detach(Observer* observer) override {
            observers.remove(observer);
        }
    
        void notify() override {
            for (Observer* observer : observers) {
                observer->update();
            }
        }
    };


    // Concrete Observers
    class ConcreteObserverA : public Observer {
    private:
        ConcreteSubject* subject;
        std::string observerState;
    
    public:
        ConcreteObserverA(ConcreteSubject* sub) : subject(sub), observerState(sub->getState()) {
            subject->attach(this);
        }
    
        ~ConcreteObserverA() override {
            subject->detach(this);
        }
    
        void update() override {
            observerState = subject->getState();
            std::cout << "ConcreteObserverA: State updated to " << observerState << std::endl;
        }
    
        void displayState() const {
            std::cout << "ConcreteObserverA: Current state is " << observerState << std::endl;
        }
    };
