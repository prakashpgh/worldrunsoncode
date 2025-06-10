/*'''
https://leetcode.com/problems/combination-sum/description/

1) Note we dont need exactly k numbers in the combination
2) same number can be repeated

Parameters: index of candidates, we only want to consider the candidates equal to or after the index
            solv[]
            current_sum
Choice:
    with same index => since the same number can be repeated.    
    to call recursively with same index, updated_sum,
End criteria:
    sum == target
        => success
    sum > target     
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
            pattern.push_back(candidates[i]);
            sum += candidates[i];
            //we start from i since same number is allowed more than once
            recur(candidates, i, sum, pattern);

            pattern.pop_back();
            sum -= candidates[i];
        }
    }

    public:

    std::vector<std::vector<int>> combination_sum(std::vector<int> candidates, int target) {
        this->target = target;
        results.clear();
        std::vector<int> pattern;
        recur(candidates, 0, 0, pattern);
    
        return results;
    }
    
};



int main() {
    std::vector<int> candidates = {2,3,6,7};
    int target = 7;
    //#Output: [[2,2,3],[7]};
    Solve solve;
    auto results = solve.combination_sum(candidates, target);
    print_vector_of_vector(results);
    
    
    candidates = {2,3,5};
    target = 8;
    //#Output: [[2,2,2,2],[2,3,3],[3,5]]
    
    
    candidates = {2};
    target = 1;
    //#Output: []
}
