/*
https://leetcode.com/problems/evaluate-division/
https://www.geeksforgeeks.org/problems/division-problem4236/1

create the graph in the form of dictionary:
    src : [(dest:value) ]

    do a dfs.. from src to destination..
            visited
            exit condition
            
*/


#include<iostream>
#include<tuple>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<unordered_map>
using namespace std;

class Solution_1 {
private:
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> adj_list;
    std::set<std::string> visited;

    double dfs(const std::string& src, const std::string& dest, double product ) {
        if (src == dest) {
            return product;
        }
        const auto& neighbors = adj_list[src];
        for(const auto& nei : neighbors) {
            auto s = nei.first;
            if(visited.find(s) == visited.end()) {
                visited.insert(s);
                double result = dfs(s, dest, product * nei.second);
                if(result != -1.0) {
                    return result;
                }
            }
        }
        return -1.0;
    }


public:
std::vector<double> evaluate_division(const std::vector<std::vector<std::string>>& equations, 
                                    const std::vector<double>& values, 
                                    const std::vector<std::vector<std::string>>& queries)  {
    std::vector<double> results;
    adj_list.clear();
    int len_eq = equations.size();
    for(int i = 0; i < len_eq; ++i ) {
        const auto& entry = equations[i];
        adj_list[entry[0]].push_back({entry[1], values[i]});
        adj_list[entry[1]].push_back({entry[0], 1.0/values[i]}); 
    }
    
    int l_query = queries.size();
    for(int i = 0; i < l_query; ++i) {
        const auto& query = queries[i];
        const std::string& src = query[0];
        const std::string& dest = query[1];
        visited.clear();
        if(adj_list.find(src) == adj_list.end() || adj_list.find(dest) == adj_list.end()) {
            results.push_back(-1.0);
        } else {
            visited.insert(src);

            results.push_back(dfs(src, dest, 1.0));
        }
    }

    return results;
}
};

int main() {
    
    std::vector<std::vector<std::string>> equations = {{"a","b"},{"b","c"}};
    
    std::vector<double> values = {2.0,3.0};
    std::vector<std::vector<std::string>> queries = { {"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    //Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
    Solution solve;
    std::vector<double> results;
    results = solve.evaluate_division(equations, values, queries);
    print_vector(results);
    
    equations = {{"a","b"},{"b","c"},{"bc","cd"}};
    values = {1.5,2.5,5.0};
    queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    //Output: [3.75000,0.40000,5.00000,0.20000]
    results = solve.evaluate_division(equations, values, queries);
    print_vector(results);


    equations = {{"a","b"}};
    values = {0.5};
    queries = {{"a","b"}, {"b","a"},{"a","c"},{"x","y"}};
    //Output: [0.50000,2.00000,-1.00000,-1.00000]
    results = solve.evaluate_division(equations, values, queries);
    print_vector(results);
}



