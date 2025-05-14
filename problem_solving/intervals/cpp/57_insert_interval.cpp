/*
https://leetcode.com/problems/insert-interval/
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"


std::vector<std::vector<int>> insert_interval(const std::vector<std::vector<int>>& intervals,
                                                std::vector<int>& newInterval ) {
    std::vector<std::vector<int>> results;
    int len = intervals.size();
    bool inserted = false;
    for(int i = 0; i < len; ++i) {
        if(newInterval[1] < intervals[i][0]) {
            if(!inserted) {
                results.push_back(newInterval);
                inserted = true;
            }
            results.push_back(intervals[i]);
        } else if(newInterval[0] > intervals[i][1]) {
            results.push_back(intervals[i]);
        } else {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
        }
    }
    if(!inserted) {
        results.push_back(newInterval);
    }
    return results;
}


int main() {
    std::vector<std::vector<int>> intervals;
    intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    std::vector<int> new_interval = {4,8};
    //#Output: [[1,2],[3,10],[12,16]]
    //#Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
    //print_vector_of_vector(intervals);
    std::vector<std::vector<int>> result = insert_interval(intervals, new_interval);
    print_vector_of_vector(result);


    intervals = {{1,3},{6,9}};
    new_interval = {2,5};
    //#Output: [[1,5],[6,9]]
    //#Example 2:
    print_vector_of_vector(intervals);
    result = insert_interval(intervals, new_interval);
    print_vector_of_vector(result);
    return 0;
}