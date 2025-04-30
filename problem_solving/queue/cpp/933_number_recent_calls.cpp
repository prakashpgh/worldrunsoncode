/*
'''
https://leetcode.com/problems/number-of-recent-calls/
933_number_recent_calls.py

use of q => q will hold only [t-3000, t]
'''
*/
#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;
#include<algorithm>
#include<queue>

class RecentCounter {
    private:
    std::queue<int> times;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        times.push(t);
        while(t - q.front() > 3000)   {
            q.pop();
        } 
        return q.size();
    }
};


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)



