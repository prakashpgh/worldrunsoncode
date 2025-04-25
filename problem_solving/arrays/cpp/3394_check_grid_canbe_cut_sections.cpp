/*
https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections

note the cuts can be horizontal or vertical..

Horizontal cut:
    sort by r[1]
    prev_max_y = rects[0][3]
    iterate over the rectangles...
        check if the ymax crosses n.  if yes, its false.
    
*/
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>


class Solution {
public:

bool check_for_horizontal_cuts(int n, std::vector<std::vector<int>>& rectangles) {
    print_vector_of_vector(rectangles);
    std::sort(rectangles.begin(), rectangles.end(), [] (const std::vector<int>& left, std::vector<int>& right) {
        return left[1] < right[1];
    });
    print_vector_of_vector(rectangles);

}

bool check_for_vertical_cuts(int n, std::vector<std::vector<int>>& rectangles) {
    print_vector_of_vector(rectangles);
    std::sort(rectangles.begin(), rectangles.end(), [] (const std::vector<int>& left, std::vector<int>& right) {
        return left[0] < right[0];
    });
    print_vector_of_vector(rectangles);

}



bool check_grid_canbe_cut_sections(int n, std::vector<std::vector<int>>& rectangles) {
    check_for_horizontal_cuts(n, rectangles);
    check_for_vertical_cuts(n, rectangles);
    return true;
}


};

int main() {
    std::vector<std::vector<int>> rectangles = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};
    int n=5;
    Solution solve;
    solve.check_grid_canbe_cut_sections(n, rectangles);
}

/*
n = 5

rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
result = check_grid_canbe_cut_sections(n, rectangles)
#true
print("result=" + str(result))


n = 4
rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]
result = check_grid_canbe_cut_sections(n, rectangles)
#true
print("result=" + str(result))



n = 4
rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]
#Output: false
result = check_grid_canbe_cut_sections(n, rectangles)
print("result=" + str(result))


n = 5
rectangles = [[0,0,1,2], [0,2,1,4], [0,4,1,5]]
result = check_grid_canbe_cut_sections(n, rectangles)
print("result=" + str(result))


n = 3
rectangles = [[0,0,1,1], [0,2,1,3], [2,0,3,1]]
result = check_grid_canbe_cut_sections(n, rectangles)
print("result=" + str(result))
*/