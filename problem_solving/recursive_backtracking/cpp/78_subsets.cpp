/*
https://leetcode.com/problems/subsets/description/

recursive backtracking

Choice:  either choose a number or not, go to higher index to avoid repetition
                    e.g [1,2,3]  once you are dealt with 1, for 2, consider only 3  in the recursion tree

exit criteia:
    when index = N-1

Parameters: index
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>


class Solution {
private:
    std::vector<std::vector<int>> results;

    void recur(std::vector<int>& input, int index, std::vector<int>& subset) {
        if(index == input.size()) {
            results.push_back(subset);
            return;
        }

        recur(input, index+1, subset);

        subset.push_back(input[index]);
        recur(input, index+1, subset);
        subset.pop_back();
    }

public:
std::vector<std::vector<int>> subsets(std::vector<int>& input ) {
    results.clear();
    std::vector<int> subset;
    recur(input, 0, subset);
    return results;
}

};


int main() {
    std::vector<int> input;
    std::vector<std::vector<int>> results;
    input = {1,2,3};
    Solution solve;
    results = solve.subsets(input);
    print_vector_of_vector(results);

    input = {0};
    results = solve.subsets(input);
    print_vector_of_vector(results);

    return 0;
}
