/*'''
https://leetcode.com/problems/find-median-from-data-stream/

the idea here is to maintain 2 heaps for the 2 parts of the data..
    left heap is a max heap.
    right heap is min heap..

    left stores the lower part of the array => max heap
    right stores the higher part of the array. => min heap

    add => push to left, pop , push to right, 
            if len right > len left, pop from right, push to left

    median 


'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
    }
    
    double findMedian() {
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */        

        
    
medianFinder = MedianFinder()
medianFinder.addNum(1)    # arr = [1]
medianFinder.addNum(2)    # arr = [1, 2]
result = medianFinder.findMedian() # return 1.5 (i.e., (1 + 2) / 2)
print("result:" + str(result))
medianFinder.addNum(3)    # arr[1, 2, 3]
result = medianFinder.findMedian() # return 2.0
print("result:" + str(result))


#---------
medianFinder = MedianFinder()
medianFinder.addNum(-1)    
result = medianFinder.findMedian() 
print("result:" + str(result))

medianFinder.addNum(-2)    
result = medianFinder.findMedian() 
print("result:" + str(result))

medianFinder.addNum(-3)    
result = medianFinder.findMedian() 
print("result:" + str(result))

medianFinder.addNum(-4)    
result = medianFinder.findMedian() 
print("result:" + str(result))

medianFinder.addNum(-5)
result = medianFinder.findMedian() 
print("result:" + str(result))
