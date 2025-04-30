/*
https://leetcode.com/problems/all-paths-from-source-to-target/
#bloomberg

dfs/bfs and backtracking...

dfs
    push
        dfs
    pop


time:   O(n * P)  => p is numbr of paths
             O(n * 2**n)
            O(n) for each path... P paths possible ... O(n. P)... worst case O(n * 2**n)

space: O(n * P)
            P = numbe of paths.
----------------------
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

#include<queue>

std::vector<std::vector<int>> all_paths_bfs(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    if(n == 0) {
        return {};
    }
    std::vector<std::vector<int>> all_paths;
    std::queue<std::vector<int>> q;
    std::vector<int> path{0};
    q.push(path);

    while(!q.empty()) {
        std::vector<int> current = q.front();
        q.pop();

        int last_node = current.back();
        if(last_node == n-1) {
            all_paths.push_back(current);
        } else {
            for(int nei : graph[last_node]) {
                auto new_path = current;
                new_path.push_back(nei);
                q.push(new_path);
            }
        }

    }
    return all_paths;
}


int main() {
    std::vector<std::vector<int>> graph = {{1,2},{3},{3},{}};
    Solution solve;
    auto result = solve.all_paths_source_target(graph);
    print_vector_of_vector(result);

    graph = {{1,2},{3},{3},{}};
    std::cout << "bfs " << std::endl;
    result = all_paths_bfs(graph);
    print_vector_of_vector(result);
    
}
