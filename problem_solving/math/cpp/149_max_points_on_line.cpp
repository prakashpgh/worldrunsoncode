/*
https://leetcode.com/problems/max-points-on-a-line/

Idea:
    iterate the points
    {
    P1
    for P1, find the slope with other points..
        slope calcs: if x and y match, duplicate of the P1 points
            use map<{dx/g, dy/g}> as the key.
        update the local max..
    update the max_points.
    }

*/
#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<numeric>




int max_points_on_line(const std::vector<std::vector<int>>& points) {
    int n = points.size();
    int max_points = 0;
    if(n<=2) {
        return n;
    }
    for(int i = 0; i < n; ++i) {
        std::map<std::pair<int, int>, int> map;
        int x1= points[i][0];
        int duplicate = 1;
        int y1= points[i][1];
        int local_max = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            int x2= points[j][0];
            int y2= points[j][1];
            int dx = x1-x2;
            int dy = y1-y2;
            if(dx == 0 && dy == 0) {
                duplicate += 1;
            }
            std::pair<int, int> slope_key;
            if(dx == 0) {
                slope_key = {1,0};
                map[slope_key] += 1;
            } else {
                int g = std::gcd(dx, dy);
                slope_key = {dy/g, dx/g};
                map[slope_key] += 1;
            }
            local_max = std::max(local_max, map[slope_key] + duplicate);
        }
        max_points = std::max(max_points, local_max);
    }
    return max_points;
}


int main() {
    std::vector<std::vector<int>> points = {{1,1},{2,2},{3,3}};
    //Output: 3
    int mx = 0;
    mx = max_points_on_line(points);
    std::cout << "result: " << mx << std::endl;
    
    points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    mx = max_points_on_line(points);
    std::cout << "result: " << mx << std::endl;
    //Output: 4
    return 0;
}