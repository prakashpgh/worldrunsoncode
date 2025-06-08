/*
https://leetcode.com/problems/smallest-number-in-infinite-set/
2336_smallest_number_in_infinite_series.py

use of min_heap
store +ve integers thru infinity.
You are not actually storing it...
    if some one pops, then check if in heap,else use the current pointer



*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<queue>
#include<queue>

class SmallestInfiniteSet {
    private:
    int current;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pr;//to get the smallest after addback.
    std::set<int> added_back;//to check if added.

    public:
    SmallestInfiniteSet() 
        : current(1)
    {

    }

    int popSmallest() {
        int smallest = current;
        if(!pr.empty() && pr.top() < current) {
            smallest = pr.top();
        }
        if(smallest == current) {
            int tmp = current;
            current++;
            return tmp;            
        } else {
            int tmp = pr.top();
            added_back.erase(tmp);
            pr.pop();
            return tmp;
        }
    }

    void addBack(int num) {
        if(num < current && added_back.find(num) == added_back.end() ) {
            added_back.insert(num);
            pr.push(num);
        }
    }
};


int main() {
    return 0;
}