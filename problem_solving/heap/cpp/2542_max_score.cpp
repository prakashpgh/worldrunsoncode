/*'''
https://leetcode.com/problems/maximum-subsequence-score/

pair n1 and n2
sort by n2... in decreasing..of n2   => why sort => to ease the finding of the min. num2.

 => finding the max
    we find all the possible sums... * num2.
    using min heap we know that we are having the max.  k from n2.

iterate this..pairs
    heap push 
    if size > k, heap pop, so we have max k elements in the heap.
    when heap size == k, find the score, compare with the max score.

'''*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
#include<queue>


long long max_susequence_score(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    int len = nums1.size();
    std::vector<std::pair<int, int>> pairs(len);
    
    for(int i = 0; i < len; ++i)  {
        pairs[i] = {nums2[i], nums1[i]};
    }
    //sort in descending n2  order.
    std::sort(pairs.begin(), pairs.end(), [] (const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first;
    });

    long long current_sum = 0;
    long long max_value = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for(int i = 0; i < len; ++i)  {
        int val1 = pairs[i].second;
        int val2 = pairs[i].first;
        current_sum += val1;
        min_heap.push(val1);
        if(min_heap.size() > k) {
            current_sum -= min_heap.top();
            min_heap.pop();
        }
        if(min_heap.size() == k) {
            max_value = std::max(max_value, current_sum*val2);
        }
    }
    return max_value;
}
    


int main() {
    return 0;
}