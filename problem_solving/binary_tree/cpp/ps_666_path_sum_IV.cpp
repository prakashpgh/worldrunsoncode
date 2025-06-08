/*
https://leetcode.com/problems/path-sum-iv/

Idea:
    1) mapping the 3 digit numbers => depth+position = value map
    2) dfs => if reached the leaf, add to the total.
    3) do on the l and r childs

*/

#include<iostream>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;


class Solution1 {
    private:
    std::unordered_map<int, int> nodeid_map;
    int total_sum = 0;
    public:

    void dfs(int node_id, int current_sum) {
        if(nodeid_map.find(node_id) == nodeid_map.end()) {
            return;
        }
        current_sum += nodeid_map[node_id];
        int d = node_id / 10;
        int p = node_id % 10;
        int l = (d+1)*10 + (2*p - 1);
        int r = (d+1)*10 + (2*p);

        //if leaf node..
        if(nodeid_map.find(l) == nodeid_map.end() && 
           nodeid_map.find(r) == nodeid_map.end()) {
            total_sum += current_sum;
            return;
        }
        dfs(l, current_sum);
        dfs(r, current_sum);
    }
    
    
    int pathsum(std::vector<int>& nums ) {
        nodeid_map.clear();
        total_sum = 0;
        for( int n : nums ) {
            int d = n / 100;
            int v = n % 10;
            int p = (n % 100) / 10;
            nodeid_map[10*d + p] = v; 
        }
        dfs(11, 0);

        return total_sum;
    }
    
};



int main() {
    //#root = [10,5,-3,3,2,null,11,null, null, null, 1]
    //#targetSum = 8
    std::vector<int> nums1 = {113, 215, 221};
    Solution1 sol;
    int sum = sol.pathsum(nums1);
    std::cout << "sum: " << sum << std::endl;

    nums1 = {113, 221};
    sum = sol.pathsum(nums1);
    std::cout << "sum: " << sum << std::endl;
    return 0;
}