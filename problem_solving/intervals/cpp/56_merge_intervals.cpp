#include<vector>
#include<algorithm>
#include "../../utils/utils.h"
using namespace std;

vector<vector<int>> merge_intervals(vector<vector<int>> intervals) {
    if (intervals.empty()) {
        return intervals;
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged = {intervals[0]};
    for(int i = 1; i < intervals.size(); ++i ) {
        vector<int>& current = intervals[i]; 
        vector<int>& latest_merged = merged.back();
        if (current[0] >= latest_merged[0] && current[0] <= latest_merged[1] ) {
            latest_merged[1] = max(latest_merged[1], current[1]);
        } else {
            merged.push_back(current);
        }
    }
    return merged;
}




int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> results = merge_intervals(intervals);
    //print_vector(result);
    for(const auto& r : results) {
        print_vector(r);
    }
    //Output: {{1,6},{8,10},{15,18}}


    intervals = {{1,4},{4,5}};
    results = merge_intervals(intervals);
    for(const auto& r : results) {
        print_vector(r);
    }
    //print_vector(result);
    //Output: {{1,5}}
    return 0;
}