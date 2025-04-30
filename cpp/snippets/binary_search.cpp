/*
1) traditional binary search

2) capacity problems..

3) rotated array
        get the index of min. element using binary search
        case I: no rotation
        case II: left half
        case III: right half


return guidelines:
1) exact match:
    if arr[mid] == target, return mid, else -1

2) BOUNDARY PROBLEMS  FIRST/LAST OR CONDITION
*/
//binary search in rotated...
//
/*
When left > right (or left == right + 1):
left: First index where the condition holds (e.g., first arr[i] >= target).
right: Last index where the condition doesn’t hold.
If left == right, that’s often the answer for peak or exact match problems.
*/

#include<vector>
#include<iostream>

//EXACT MATCH case
// //704
https://leetcode.com/problems/binary-search/
int search(std::vector<int>& nums, int target) {
    int len = nums.size();
    int l = 0;
    int r = len -1;
    while(l <= r) {
        int m = l + (r-l)/2;
        if(nums[m] == target) {
            return m;
        } 
        else if(nums[m] < target) {
            l = m + 1;
        }
        else {
            r = m -1;
        }
    }
    return -1;
}

//BOUNDARY 
//34
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
int firstPosition(vector<int>& nums, int target) {
    int left = 0
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1; // Move right to find first
        }
        else {
            left = mid + 1;
        }
    }
    return left < nums.size() && nums[left] == target ? left : -1;
}


//35
//https://leetcode.com/problems/search-insert-position/
int searchInsert(vector<int>& nums, int target) {
    int left = 0
    right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left; // Insertion point
}


//Optimization
//https://leetcode.com/problems/split-array-largest-sum/description/
/*

*/
int splitArray(std::vector<int>& nums, int m) {
        long long left = 0, right = 0;
        
        // Find the bounds for binary search
        for (int num : nums) {
            left = std::max(left, (long long)num); // Max element
            right += num; // Sum of all elements
        }
        
        // Binary search for the minimum largest sum
        while (left < right) {
            long long mid = left + (right - left) / 2;
            
            // Check if we can split into m or fewer subarrays with max sum <= mid
            int count = 1; // Number of subarrays
            long long currSum = 0;
            
            for (int num : nums) {
                if (currSum + num > mid) {
                    count++; // Start a new subarray
                    currSum = num; // New subarray starts with current number
                } else {
                    currSum += num;
                }
            }
            
            // Adjust binary search bounds
            if (count <= m) {
                right = mid; // Try a smaller maximum sum
            } else {
                left = mid + 1; // Need a larger maximum sum
            }
        }
        
        return left;
    }


//PEAK
int findPeakElement(vector<int>& nums) {
    int left = 0
    int right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}


int find_min_rotated_sorted_vector(const std::vector<int>& nums) {
    int l = 0;
    int r = nums.size()-1;
    while(l < r) {
        int m = l + (r-l)/2;
        if(nums[m] > nums[r]) {
            l = m+1;
        } else {
            r = m;
        }
    }
    return nums[l];
}


int find_min_index_duplicates_rotated_sorted_vector(const std::vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while(l < r) {
        int m = l + (r-l)/2;
        if(nums[m] > nums[r]) {
            l = m + 1;
        } else if(nums[m] < nums[r]) {
            r = m;
        } else {
            //here ==, so we are reducing r to remove one of the duplicates.
            r -= 1;
        }
    }
    return nums[l];
}


int main() {
    std::vector<int> nums = {11,12,13,14,15,8,9,10};
    std::cout << "find min element in the rotated sorted array:" << std::endl;
    int result = find_min_rotated_sorted_vector(nums);
    std::cout << result << std::endl;
    //8

    nums = {1,3,5};
    //Output: 1
    result = find_min_index_duplicates_rotated_sorted_vector(nums);
    std::cout << result << std::endl;


    nums = {2,2,2,0,1};
    result = find_min_index_duplicates_rotated_sorted_vector(nums);
    std::cout << result << std::endl;
    //Output: 0
}
