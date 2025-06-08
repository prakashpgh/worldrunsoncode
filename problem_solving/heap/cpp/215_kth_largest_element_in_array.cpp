/*
'''
https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Approach I:
    Sorting ... descending order using rbegin() & rend()
    nums[k-1]
    time: O(n log(n))
    space: O(1)

Approach II:
    Using min heap
        std:::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        time:   n * log K
        space:  O(k)

Heap approach
1) iterate the array and keep pushing into the heap.
2)  if size(heap) > k pop

At the end, do a pop... thats the kth element
'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"



int find_KthLargest(const std::vector<int>& nums, int k) {
    int result = 0;
    std::sort(nums.begin(), nums.end());
    if(nums.size()-k >= 0) {
        result = nums[nums.size()-k];
    }
    return result;
}


int findKthLargest_using_min_heap(const std::vector<int>& nums, int k) {
    int result = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for(int i =0; i < nums.size(); ++i) {
        min_heap.push(nums[i]);
        if(min_heap.size() > k) {
            min_heap.pop();
        }
    }
    if(!min_heap.empty()) {
        result = min_heap.top();
    }
    return result;
}



int main() {
    std::vector<int> nums;
    nums = {3,2,1,5,6,4};
    int k = 2;
    int result = findKthLargest(nums, k);
    std::cout << "result: " << result << std::endl;
    //#Output: 5

    nums = {3,2,1,5,6,4};
    result = findKthLargest_using_min_heap(nums, k);
    std::cout << "result: " << result << std::endl;

    nums = {3,2,3,1,2,4,5,5,6};
    k = 4;
    //#Output: 4
    result = findKthLargest(nums, k);
    std::cout << "result: " << result << std::endl;


    nums={1, 23, 12, 9, 30, 2, 50};
    k = 3;
    //#Output: 23;
    result = findKthLargest_using_min_heap(nums, k);
    std::cout << "result: " << result << std::endl;

    nums={12, 3, 5, 7, 19};
    k = 2;
    //#Output: 12
    result = findKthLargest_using_min_heap(nums, k);
    std::cout << "result: " << result << std::endl;
}
