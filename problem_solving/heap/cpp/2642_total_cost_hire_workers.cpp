/*'''
https://leetcode.com/problems/total-cost-to-hire-k-workers/
2642_total_cost_hire_workers
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
#include<queue>

/*
1) put candidates from left half into the heap...  default sort is by cost, index in ascending order.
2) repeat 1) from right side.
    Note, because of 1) and 2), the heap is sorted on (cost + index)
3) iterate till k => pop from heap, get the cost
*/
long long total_cost_hire_workers(std::vector<int>& costs, int k, int candidates) {
    long long result = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> min_heap;
    int l = 0;
    int r = costs.size() -1;
    for(int i = 0; i < candidates; ++i) {
        if(l <= r) {
            min_heap.push({costs[l], l});
        }
        l++;
    }

    for(int i = 0; i < candidates; ++i) {
        if(l <= r) {
            min_heap.push({costs[r], r});
        }
        r--;
    }

    for(int i = 0; i < k; ++i) {
        auto pr = min_heap.top();
        min_heap.pop();
        result += pr.first;
        
        if(l <= r) {
            if(pr.second < l) {
                min_heap.push({costs[l], l});
                l++;    
            } else {
                min_heap.push({costs[r], r});
                r--;
            }
        }
    }
    return result;
}




int main() {
    std::vector<int> costs = {17,12,10,2,7,2,11,20,8};
    int k = 3;
    int candidates = 4;
    int result = total_cost_hire_workers(costs, k, candidates);
    std::cout << "result: " << result << std::endl;
    
    return 0;
}
