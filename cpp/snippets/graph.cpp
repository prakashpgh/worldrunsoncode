#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include "../common_header.h"
#include "../utils/utils.h"
using namespace std;
#include<queue>


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
#################################################################################################
Difference between tree and graph
    1) Cycles: tree is not cyclical, graph can have cycles
    2) connectivity:  graphs can be disconnected, tree nodes are always connected
    3) Hierarchy: trees have hierarchical structure, with a root.

Spanning tree: tree that connects all the nodes
Minimum spanning tree MST
    weighted undirected graph can have multiple MSTs

Cut ~ partition of the vertices of a graph into 2 disjoint sets
Crossing edge ~ edge that connects the vertex in one set with a vertex in anothe set
    if  a crossing edge has weight less than all othe crossing edges, then its a part of MST    

####################
Kruskal algo
    https://leetcode.com/explore/featured/card/graph/621/algorithms-to-construct-minimum-spanning-tree/3856/
    1) sort the edges in the ascending order
    2) add to the MST if they dont form a cycle
        do this till we add N-1 edges


!) Prims algo
    non-visited
    visited
        make a list of unvisited vertices .. all vertices of the graph
        add one vertex to the graph
        check all the edges of the graph, get the one with minimum weight, move it to visited
        add that node.
        continue like this till nodes are in visited list

Kruskal adds the edges, Prims adds the vertices
https://leetcode.com/problems/min-cost-to-connect-all-points/description/

Prims => add vertices.
    1) visited vector
    2) min heap 
*/
int min_cost_connect_points_prims(std::vector<std::vector<int>>& points ) {
    int len = points.size();
    if(len <= 1) {
        return 0;
    }
    //visited array..
    std::vector<int> visited(len, false);
    //cost, index
    std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<> > pq;
    pq.emplace(0, 0);
    int points_used = 0;
    int total_cost = 0;
    while (!pq.empty() && points_used < len) {
        auto [cost, u] = pq.top();
        pq.pop();

        if(visited[u]) {
            continue;
        }
        visited[u] = true;
        total_cost += cost;
        points_used++;
        //points from this points..
        for(int v = 0; v < len; ++v) {
            if(!visited[v]) {
                int dist = std::abs(points[u][0] - points[v][0]) + std::abs(points[u][1] - points[v][1]);
                pq.emplace(dist, v);
            }
        }
    }
    
    return (points_used == len) ? total_cost : -1;
}

void min_cost_connect_points_prims_demo() {
    std::vector<std::vector<int>> points;
    points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    //Output: 20
    int result = min_cost_connect_points_prims(points);
    std::cout << "min_cost_connect_points_prims " << result << std::endl;
}



/*
II) 
Single source shortest path
    BFS is used for shortest path in unweighted graph.
    https://leetcode.com/explore/featured/card/graph/622/single-source-shortest-path-algorithm/3885/

For weighted graph..
1) Dijkstra' Algo
        => shortest path from a source node to all other nodes in a weighted graph
        can only be used when weights are non-negative

        starting point
        https://leetcode.com/explore/featured/card/graph/622/single-source-shortest-path-algorithm/3862/
        Take any node..A put it in visited set
        
        1A ) take all the edges from A.  update the distance/time to reach the nodes..
        put the visited nodes in Q or stack

        Now, consider the unvisited nodes.  Repeat 1A.
        repeat till all the nodes are visited.

        1) maintain a vector of the distances of each node from the source  => keep updating it
        2) heap..min_heap... with cost as first => 
*/
#include<queue>
typedef pair<int, int> pii;

std::vector<int> dikjstra(std::vector<std::vector<pii>>& graph, int src, int n) {
    std::vector<int> distances(n, INT_MAX);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({0, src});
    //stores the min. distance.
    distances[src] = 0;
    while(!pq.empty()) {
        pii pi = pq.top();
        pq.pop();
        int d = pi.first;
        int p = pi.second;

        if(distances[p] < d) {
            continue;
        }

        for(const pii pr : graph[p]) {
            int q = pr.first;
            int dist = pr.second;
            if( distances[p] + dist < distances[q]) {
                distances[q] = distances[p] + dist;
                pq.push({distances[q], q});
            }
        }
    }
    return distances;
}

void dijkstra_demo() {
    int n = 5;
    std::vector<std::vector<pii>> graph(n);

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 8});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[2].push_back({3, 5});
    graph[2].push_back({4, 10});
    graph[3].push_back({4, 2});

    int source = 0;
    auto distances = dikjstra(graph, source, n);
    print_vector(distances);
}

/*
'''
'''
Bellman Ford alo
    single source shortest path ... even with negative weights

no need for adjacency list
B-F processes list of edges

outer loop => 1) control the number of edges in the path
                after i iterations starting from 0, it computes the shortest path to i+1 nodes
            2) propagate the shortest path
            3) 
*/
int network_delay_bellman_ford(std::vector<std::vector<int>>& times, int n, int k) {
    //initialize the distances vector
    k--;
    int len = times.size();
    std::vector<int> distances(n, INT_MAX);
    distances[k] = 0;

    //(n-1)  .. for n vertices.... 
    //other examples for the cheapest flight... up to max 1 stop => 2 edges. => we need to use up to 2
    for(int i = 0; i < n-1; ++i) {
        bool changed = false;
        for( const auto& edge : times) {
            int u = edge[0]-1;    
            int v = edge[1]-1;
            int w = edge[2];
            //u -> v
            if(distances[u] != INT_MAX && distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                changed = true;
            }
        }
        if(!changed) {
            break;
        }
    }
    int result=0;
    for(int i = 0; i < n; ++i) {
        if(distances[i] == INT_MAX) {
            return -1;
        } 
        result = std::max(result, distances[i]);
    }
    return result;
}

void network_delay_bellman_ford_demo() {
    std::vector<std::vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    int result = network_delay_bellman_ford(times, n, k);
    std::cout << "network_delay_bellman_ford_demo: " << result << std::endl;
    return;
}


/*
'''
Network delay time - 743 - single source shortest path.
https://leetcode.com/explore/featured/card/graph/622/single-source-shortest-path-algorithm/3863/

Find minimum times to reach all nodes
    vector<int> => distance. with INT_MAX
    priority heap => min heap 
        update the distance vector
    iterate the distance vector to find the min. distance.
'''
*/
int network_delay_time(std::vector<std::vector<int>>& times, int n, int k) {
    //build adjacency list..
    std::vector<std::vector<std::pair<int, int>>> adj_list(n+1);
    for(const auto& edge : times) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj_list[u].push_back({v, w});
    }

    //array..to store the min distances. in a vector.
    std::vector<int> dist(n+1, INT_MAX);
    dist[k] = 0;

    //use min heap...and push the src..
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.emplace(0, k);

    while(!pq.empty()) {
        auto pr = pq.top();
        int d = pr.first;
        int u = pr.second;
        pq.pop();

        if(d > dist[n]) {
            continue;
        }
        //find all possible targets from the src.
        for(const auto e : adj_list[u]) {
            auto v = e.first;
            auto w = e.second;
            if( dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    print_vector(dist);
    int result = 0;
    for(int i = 1; i <= n; ++i) {
        if(dist[i] == INT_MAX) {
            return -1;
        }
        result = std::max(result, dist[i]);
    }

    return result;
}

void network_delay_time_demo() {
    std::vector<std::vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    int result = network_delay_time(times, n, k);
    std::cout << "network_delay_time_demo: " << result << std::endl;
}


/*
'''
Cheapest flights withn k stops
leetcode-787
https://leetcode.com/explore/featured/card/graph/622/single-source-shortest-path-algorithm/3867/

//use bellman ford...
//outer loop k+1 for k stops
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

/*
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
*/
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
/*
DFS
1) Use stack
t: O(V+E)
s: O(V)
*/
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
    std::cout << "#######################adjacency list" << std::endl;
    std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}};
    int n = 5;
    auto adj_list = edges_to_adjacency_list(n, edges);
    print_adjacency_list(n, adj_list);

    //bfs..
    std::cout << "#######################bfs_begin" << std::endl;
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
    std::cout << "###########################dfs_begin" << std::endl;
    grid = {
                    {'1','1','1','1','0'},
                    {'1','1','0','1','0'},
                    {'1','1','0','0','0'},
                    {'0','0','0','0','0'}
    };
    int result = solve.dfs_solve(grid);
    std::cout << "result: " << result << std::endl;

    //dj
    std::cout << "###########################Dijkstra_begin" << std::endl;
    dijkstra_demo();

    std::cout << "###########################network_delay_time_demo" << std::endl;
    network_delay_time_demo();

    std::cout << "########################### network_delay_bellman_ford_demo" << std::endl;
    network_delay_bellman_ford_demo();

    std::cout << "########################### min_cost_connect_points_prims_demo" << std::endl;
    min_cost_connect_points_prims_demo();
    return 0;
}
