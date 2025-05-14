/*
https://leetcode.com/problems/non-overlapping-intervals/

sort by end time..
iterate.
    if start < end time
        increment
    else
        update end time
*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
using namespace std;


int erase_overlapping_intervals(std::vector<std::vector<int>>& intervals ) {
    std::sort(intervals.begin(), intervals.end(), [] (const std::vector<int>& lhs, const std::vector<int>& rhs) {
        return lhs[1] < rhs[1];
    });

    int len = intervals.size();
    if(len == 0) {
        return 0;
    }
    int end_time = intervals[0][1];
    int count = 0;
    for(int i = 1; i < intervals.size(); ++i) {
        if(intervals[i][0] < end_time) {
            count += 1;
        } else {
            end_time = intervals[i][1];
        }
    }
    return count;
}

        
int main() {
    std::vector<std::vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    //#Output: 1
    int result = erase_overlapping_intervals(intervals);
    std::cout << "result = " << result << std::endl;
    
    intervals = {{1,2},{1,2},{1,2}};
    //#Output: 2
    result = erase_overlapping_intervals(intervals);
    std::cout << "result = " << result << std::endl;
    
    intervals = {{1,2},{2,3}};
    //#Output: 0
    result = erase_overlapping_intervals(intervals);
    std::cout << "result = " << result << std::endl;
}
