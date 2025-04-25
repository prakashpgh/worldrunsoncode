/*
https://leetcode.com/problems/all-paths-from-source-to-target/

dfs/bfs and backtracking...

dfs
    push
        dfs
    pop

bfs 
    q.push{node, path}

    2**N * N  => all possible paths
    Normal graph => single path alog O(V + E)

    dfs
        space(O(N))

    bfs
        space(O( 2**N  *  N))
            factor N comes from the copying of the path to the result

*/


#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
#include<vector>

class Solution {
    private:
    std::vector<std::vector<int>> results;

    private:
    void dfs(const std::vector<std::vector<int>>& graph, std::vector<int>& path, int node) {
        if(node == graph.size()-1) {
            results.push_back(path);
            return;
        }

        for( int node : graph[node]) {
            path.push_back(node);
            dfs(graph, path, node);
            path.pop_back();
        }
    }
public:
    std::vector<std::vector<int>> all_paths_source_target(const std::vector<std::vector<int>>& graph) {
        std::vector<int> path{0};
        dfs(graph, path, 0);
        return results;
    }
};


int main() {
    std::vector<std::vector<int>> graph = {{1,2},{3},{3},{}};
    Solution solve;
    auto result = solve.all_paths_source_target(graph);
    print_vector_of_vector(result);
}
