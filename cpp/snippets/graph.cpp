/*
Disjoint set or union-find
    Useful to check if the vertices are connected
    disjoint sets => sets that have nothing in common
    => useful for finding connectivity between graph nodes

    Idea:
        nodes that are connected belong to a set, set has a head or root

    Implementation:
        root array: initialize with size = number of nodes, with indexes for the nodes, values = indexes
        array stores the parent of the element, (index:parent)
        parent node

        *** root node => its parent is itself
        *** Connected => if root nodes are esame

        When we add a new node to this, we check if any of the vertices already exist in the root array and then assign root accordingly 

    find
        => finds the absolute root of a function

    connected() => find the root nodes.  If the root nodes are equal, they are connected

    union() => unions 2 vertices and makes their root nodes same


Ways to implement a disjoint set
1) QuickFind => 
    array => we directly store the "root" of an index.. 

    find is faster  O(1)
    https://leetcode.com/explore/featured/card/graph/618/disjoint-set/3878/

    Union: directly connected => pairs of direct connections    O(N)
    create disjoint sets from the Union
        head of the set

            find() => returns the root          =>  O(1)
                    if root parent of an element are same, then they are in the same set, else in a different set

            union(0,1) => will make the root node same  =>  O(N)
            connected  =>   O(1)
                space: O(N)

#-------------------------------------------
QuickUnion
    array stores the parent node
    connect => the roots are connected...
  
'''
'''
Difference between tree and graph
    Cycles: tree is not cyclical, graph can have cycles
    connectivity:  graphs can be disconnected, tree nodes are always connected
    Hierarchy: trees have hierarchical structure, with a root.


BFS
time: O(V+E)
   space: O(V)  => use of Q 
Use Q
Process all vertices of a level befor ethe next level

1) shortest path between nodes where all edges have equal and +ve weights.  => BFS
2) if path exists between 2 nodes   => leetcode-1971
3) all paths from the source to the target => leetcode-797
4) populating next right pointers 
5) shortest path in binary matrix => https://leetcode.com/explore/featured/card/graph/620/breadth-first-search-in-graph/3896/
6) level order traversal => https://leetcode.com/explore/featured/card/graph/620/breadth-first-search-in-graph/3897/
7) rotting oranges => https://leetcode.com/explore/featured/card/graph/620/breadth-first-search-in-graph/3898/


DFS
1) Use stack
t: O(V+E)
s: O(V)


Spanning tree: tree that connects all the nodes
Minimum spanning tree MST
    weighted undirected graph can have multiple MSTs

Cut ~ partition of the vertices of a graph into 2 disjoint sets
Crossing edge ~ edge that connects the vertex in one set with a vertex in anothe set
    if  a crossing edge has weight less than all othe crossing edges, then its a part of MST    


Kruskal algo
    https://leetcode.com/explore/featured/card/graph/621/algorithms-to-construct-minimum-spanning-tree/3856/
    1) sort the edges in the ascending order
    2) add to the MST if they dont form a cycle
        do this till we add N-1 edges

        E logE
                leetcode-1584

Prims algo
    non-visited
    visited
        make a list of unvisited vertices .. all vertices of the graph
        add one vertex to the graph
        check all the edges of the graph, get the one with minimum weight, move it to visited
        add that node.
        continue like this till nodes are in visited list




Kruskal adds the edges, Prims adds the vertices
'''

'''
Single source shortest path
    BFS is used for shortest path in unweighted graph.
    https://leetcode.com/explore/featured/card/graph/622/single-source-shortest-path-algorithm/3885/

1) Dijkstra' Algo
        can only be used when weights are non-negative

        starting point
        https://leetcode.com/explore/featured/card/graph/622/single-source-shortest-path-algorithm/3862/
        Take any node..A put it in visited set
        
        1A ) take all the edges from A.  update the distance/time to reach the nodes..
        put the visited nodes in Q or stack

        Now, consider the unvisited nodes.  Repeat 1A.
        repeat till all the nodes are visited.

'''
'''
Bellman Ford alo
    single source shortest path ... even with negative weights



'''


'''
Network delay time
https://leetcode.com/explore/featured/card/graph/622/single-source-shortest-path-algorithm/3863/

Find minimum times to reach all nodes
'''




'''
Cheapest flights withn k stops
leetcode-787
https://leetcode.com/explore/featured/card/graph/622/single-source-shortest-path-algorithm/3867/

'''



'''
Path with minimum effort

https://leetcode.com/explore/featured/card/graph/622/single-source-shortest-path-algorithm/3952/
'''


'''
minimum height trees  MHT

https://leetcode.com/explore/featured/card/graph/623/kahns-algorithm-for-topological-sorting/3953/

'''

'''
Kahn algo ~ Topological sorting
https://leetcode.com/explore/featured/card/graph/623/kahns-algorithm-for-topological-sorting/3886/


Course schedule II


Alient dictionary
https://leetcode.com/explore/featured/card/graph/623/kahns-algorithm-for-topological-sorting/3909/

'''

1168


https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
https://leetcode.com/problems/number-of-provinces/editorial/


disjoint
https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/editorial/
    https://www.youtube.com/watch?v=2tYgeuNUpiA
    
    sort logs on timestamp
    build graph
    parse logs and update graph

*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include "../common_header.h"
#include "../utils/utils.h"
using namespace std;

//convert edges into adj. list
std::vector<std::unordered_set<int>> edges_to_adjacency_list(int n, const std::vector<std::vector<int>>& edges ) {
    //assuming the nodes are from 1 to n
    std::vector<std::unordered_set<int>> adj_list(n+1);
    for(const auto& edge : edges) {
        adj_list[edge[0]].insert(edge[1]); 
        adj_list[edge[1]].insert(edge[0]);
    }
    return adj_list;
}

void print_adjacency_list(int n, const vector<std::unordered_set<int>>& adj_list )  {
    for(int i = 1; i <= n; ++i ) {
        std::cout << i << "[";
        for(int j : adj_list[i]) {
            std::cout << j << ",";
        }
        std::cout << "]" << std::endl;
    }
}

#include<queue>
void bfs_demo_grid(std::vector<std::vector<char>>& grid, int start_row, int start_col) {
    
    int rows = grid.size();
    int cols = 0;
    if(rows > 0) {
        cols = grid[0].size();
    }
    std::vector<std::vector<int>> neighbors = {{0,-1},{-1,0},{0,1},{1,0}};
    std::queue<std::pair<int, int>> q;
    q.push({start_row, start_col});
    std::cout << start_row << "," << start_col << std::endl;
    while(!q.empty())  {
        const auto& pair = q.front();
        q.pop();
        
        int r = pair.first;
        int c = pair.second;
        //do processing
        char ch = grid[r][c];

        for(const auto& entry : neighbors) {
            int i =  entry[0];
            int j = entry[1];
            
            int row = r + i;
            int col = c + j;
            //std::cout << row << "," << col << std::endl;
            if(row < 0 || row >= rows || col < 0 || col >= cols) {
                continue;
            }
            //std::cout << "processing: " << row << "," << col << std::endl;
            if(grid[row][col] == '1') {
                std::cout << row << "," << col << " = " << grid[row][col] << std::endl;
                grid[row][col] = '0';
                q.push({row, col});
            }
        }
    }//q
}

class Solution {
public:
void dfs(std::vector<std::vector<char>>& grid, int start_row, int start_col) {
    std::vector<std::vector<int>> neighbors = {{0,-1},{-1,0},{0,1},{1,0}};
    for(const auto& nei : neighbors) {
        int r = start_row + nei[0];
        int c = start_col + nei[1];
        if(r < 0 || r >= rows || c < 0 || c >= cols) {
            continue;
        }
        if(grid[r][c] == '0') {
            continue;
        }
        grid[r][c] = '0';
        dfs(grid, r, c);
    }
}

int rows;
int cols;
int dfs_solve(std::vector<std::vector<char>>& grid) {
    rows =  grid.size();
    cols = 0;
    if(rows > 0) {
        cols = grid[0].size();
    }
    int islands = 0;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            if(grid[i][j] == '1')  {
                dfs(grid, i, j);
                islands += 1;
            }
        }
    }
    return islands;
}
};

int main() {
    std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}};
    int n = 5;
    auto adj_list = edges_to_adjacency_list(n, edges);
    print_adjacency_list(n, adj_list);

    //bfs..
    std::cout << "bfs_begin" << std::endl;
    std::vector<std::vector<char>> grid = {
                    {'1','1','1','1','0'},
                    {'1','1','0','1','0'},
                    {'1','1','0','0','0'},
                    {'0','0','0','0','0'}
    };
    int rows = grid.size();
    int cols = 0;
    if (rows > 0) {
        cols = grid[0].size();
    }
    int islands = 0;
    for(int i=0;i < rows; ++i) {
        for(int j=0;j < cols; ++j) {
            if(grid[i][j] == '1') {
                islands += 1;
                bfs_demo_grid(grid, i, j);
            }
        }
    }
    std::cout << "islands " << islands << std::endl;


    //dfs...
    Solution solve;
    std::cout << "dfs_begin" << std::endl;
    grid = {
                    {'1','1','1','1','0'},
                    {'1','1','0','1','0'},
                    {'1','1','0','0','0'},
                    {'0','0','0','0','0'}
    };
    int result = solve.dfs_solve(grid);
    std::cout << "result: " << result << std::endl;
    return 0;
}
