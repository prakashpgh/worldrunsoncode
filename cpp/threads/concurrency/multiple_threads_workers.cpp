/*
* program in which a class takes four integer arguments as input (a, b, c, and d). 
Perform addition of (a+b) on one thread, addition of (c+d) on another thread, 
and multiplication of ((a+b)*(c+d)) on the main thread.

Approach I)
	store the sum in class variables
		raw threads
		join
		need mutex to guard the sum variables

Approach II) promise
	promise and future to return the values
		raw threads
		join

Approach III) std::sync
	
*/
#include<thread>
#include<iostream>

class MultipleThreads {
	MultipleThreads(int a, int b, int c, int d) 
		: this->a(a), this->b(b), this->c(c), this->d(d)
	{}

	threadAB(std::promise<int>&& pAB) {
		pAB.set_value(a + b);
	}

	threadCD(std::promise<int>&& pCD) {
		pCD.set_value(c + d);
	}

	threadAB_async() {
		return (a + b);
	}

	threadCD_async() {
		return (c + d);
	}

	void performCalcuations_usingpromise() {
		std::promise<int> promiseAB;
		std::future<int> futureAB = promiseAB.get_future();
		std::promise<int> promiseCD;
		std::future<int> futureCD = promiseCD.get_future();
		std::thread tAB(&MultipleThreads::threadAB, this, std::move(promiseAB));
		std::thread tCD(&MultipleThreads::threadAB, this, std::move(promiseCD));

		tAB.join();
		tCD.join();
		int sumAB = futureAB.get();
		int sumCD = futureCD.get();
		int product = sumAB * sumCD;
		std::cout << product << std::endl;
	}


	void performCalcuations_using_async() {
		std::future<int> futureAB = std::sync(&MultipleThreads::threadAB, this);
		std::future<int> futureCD = std::sync(&MultipleThreads::threadCD, this);
		int sumAB = futureAB.get();
		int sumCD = futureCD.get();
		int product = sumAB * sumCD;
		std::cout << product << std::endl;
	}
private:
	int a;
	int b;
	int c;
	int d;

};


int main() {
	MultipleThreads mt(1,2,3,4);
	mt.performCalculations();
}