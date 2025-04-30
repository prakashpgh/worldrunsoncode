/*
inversions
indexes i & j such that i < j, A[i] > A[j]
Approach I: O(N**2)

Approach II: 
merge sort

*/


#include <vector>

class Solution {
public:
    long long countInversions(std::vector<int>& A) {
        std::vector<int> temp(A.size());
        return mergeSort(A, temp, 0, A.size() - 1);
    }
    
private:
    long long mergeSort(std::vector<int>& A, std::vector<int>& temp, int left, int right) {
        if (left >= right) {
            return 0;
        }
        
        int mid = left + (right - left) / 2;
        long long inversions = 0;
        
        // Recursively count inversions in left and right halves
        inversions += mergeSort(A, temp, left, mid);
        inversions += mergeSort(A, temp, mid + 1, right);
        
        // Count inversions during merge
        inversions += merge(A, temp, left, mid, right);
        
        return inversions;
    }
    
    long long merge(std::vector<int>& A, std::vector<int>& temp, int left, int mid, int right) {
        int i = left;      // Index for left subarray
        int j = mid + 1;   // Index for right subarray
        int k = left;      // Index for temp array
        long long inversions = 0;
        
        while (i <= mid && j <= right) {
            if (A[i] <= A[j]) {
                temp[k++] = A[i++];
            } else {
                // A[j] < A[i], so A[j] forms inversions with all elements from i to mid
                inversions += mid - i + 1;
                temp[k++] = A[j++];
            }
        }
        
        // Copy remaining elements from left subarray, if any
        while (i <= mid) {
            temp[k++] = A[i++];
        }
        
        // Copy remaining elements from right subarray, if any
        while (j <= right) {
            temp[k++] = A[j++];
        }
        
        // Copy merged elements back to original array
        for (k = left; k <= right; ++k) {
            A[k] = temp[k];
        }
        
        return inversions;
    }
};