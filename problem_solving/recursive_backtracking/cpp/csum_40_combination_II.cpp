/*
'''
https://leetcode.com/problems/combination-sum-ii/description/

each number can be used only once.

choices:
    try for all the numbers in the candidates

'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
#include<math.h>


class Solve {
    private:
    std::vector<std::vector<int>> results;    
    int target;

    void recur(std::vector<int> candidates, int index, int sum, std::vector<int>& pattern) {
        if(sum == target) {
            results.push_back(pattern);
            return;
        } else if(sum > target) {
            return;
        }

        for(int i = index; i < candidates.size(); ++i)  {
            //*** */[1, 2, 2, 3], target = 5 => [1,2,2] & [2,3] => we should not have repetiion
            //this works only if there is sorting.
            if(i > index && candidates[i] == candidates[i-1]) {
                continue;
            }
            pattern.push_back(candidates[i]);
            sum += candidates[i];
            //we start from i+1 since same number is not allowed more than once
            recur(candidates, i+1, sum, pattern);

            pattern.pop_back();
            sum -= candidates[i];
        }
    }

    public:

    std::vector<std::vector<int>> combination_sum(std::vector<int> candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        this->target = target;
        results.clear();
        std::vector<int> pattern;
        recur(candidates, 0, 0, pattern);
    
        return results;
    }
    
};



int main() {
    std::cout << "----------" << std::endl;
    std::vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    //#Output: [[1,1,6],[1,2,5],[1,7],[2,6]};
    Solve solve;
    auto results = solve.combination_sum(candidates, target);
    print_vector_of_vector(results);

    std::cout << "----------" << std::endl;
    candidates = {2,5,2,1,2};
    target = 5;
    //#Output: [[1,1,6],[1,2,5],[1,7],[2,6]};
    results = solve.combination_sum(candidates, target);
    print_vector_of_vector(results);

    std::cout << "----------" << std::endl;
    candidates = {2,5,2,1,2};
    target = 7;
    //
    results = solve.combination_sum(candidates, target);
    print_vector_of_vector(results);

}
