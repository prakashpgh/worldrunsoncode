/*
'''
https://leetcode.com/problems/combination-sum-iii/description/

requirements: 1) we need k numbers in the combination  2) same number cannot be repeated

choice:
    append to the combination - all the numbers greater than that number

parameters: 
    number, sum_remaining, combination


exit criteria
    combination length == k => success  && remain == 0  => append to the result

    failure
        if n > 9
        if remaining sum < 0 or len(com) == k

'''
*/

#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<algorithm>
#include<math.h>

class Solve {
    private:
    std::vector<std::vector<int>> results;

    void recur(std::vector<int>& pattern, int num, int sum, int k, int n) {
        if(pattern.size() == k && sum == n) {
            results.push_back(pattern);
            return;
        }
        if(sum > n || pattern.size() > k) {
            return;
        }
        for(int i = num; i < 10; ++i) {
            //optimization...
            if(sum + i > n) {
                break;
            }
            sum += i;
            pattern.push_back(i);
            //starting from i+1 as same number is not allowed to be reused.
            recur(pattern, i+1, sum, k, n);

            sum -= i;
            pattern.pop_back();
        }
    }

    public:
    std::vector<std::vector<int>> combination_sum_three( int k, int n ) {
        std::vector<int> pattern;
        int sum = 0;
        results.clear();
        recur(pattern, 1, sum, k, n);
        return results;
    }
    
};

int main() {
    int k = 3;
    int n = 7;
    //#Output: [[1,2,4]]
    Solve solve;
    auto result = solve.combination_sum_three(k, n);
    print_vector_of_vector(result);
    std::cout << "=====================" << std::endl;
    
    k = 3;
    n = 9;
    //#Output: [[1,2,6],[1,3,5],[2,3,4]]
    result = solve.combination_sum_three(k, n);
    print_vector_of_vector(result);
    std::cout << "=====================" << std::endl;
    
    k = 4;
    n = 1;
    //#Output: []
    result = solve.combination_sum_three(k, n);
    print_vector_of_vector(result);
    std::cout << "=====================" << std::endl;
}
