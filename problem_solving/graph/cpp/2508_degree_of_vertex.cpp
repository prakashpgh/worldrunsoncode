/*
https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/description/

1) find the degrees of each node.
2) find the adj. list => vector<set<int>>
3) find the number of nodes with odd degrees K, and array of the odd nodes as odd_nodes

4)  a) if k = 0, true, nothing to be done.
    b) k % 2 != 0 => k is odd, then return FALSE
    c) if k = 2, we can try if we can join the 2 odd edges... or join the same even edge to 2 odd edges
    d) k = 4 => we can see if we can join the odd edges..
    e) else false.
+*/

#include<queue>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include "../../../cpp/common_header.h"
#include "../../../cpp/utils/utils.h"
using namespace std;

class Solution {

private:
    void dfs(int u, const vector<vector<int>>& adj_list, std::set<int>& visited ) {
        visited.insert(u);
        const vector<int>& neighbours = adj_list[u];
        for(auto nei : neighbours)  {
            if(visited.find(nei) == visited.end()) {
                dfs(nei, adj_list, visited);
            }
        }
    }

public:
    bool even_degree_of_graph(int n, std::vector<std::vector<int>> edges) {
        std::cout << "============================" << std::endl;
        std::vector<int> degrees(n+1);
        int n_edges = edges.size();
        vector<unordered_set<int>> adj_list(n+1);
        for(int i = 0; i < n_edges; ++i) {
            degrees[edges[i][0]]++;  
            degrees[edges[i][1]]++;
            adj_list[edges[i][0]].insert(edges[i][1]);
            adj_list[edges[i][1]].insert(edges[i][0]);
        }
        //print_vector(degrees);
        //print_vector_of_vector(adj_list);
        int k = 0;
        std::vector<int> odd_nodes;
        for(int i = 0; i < degrees.size(); ++i) {
            if(degrees[i] % 2 != 0) {
                if(degrees[i] == n-1) {
                    std::cout << "node with odd degree has n-1 edges" << std::endl;
                    return false;
                }
                k += 1;
                odd_nodes.push_back(i);
            }
        }
        std::cout << "k=" << k << std::endl;
        //
        std::cout << "edges with odd degree: " << k << std::endl;
        if(k==0) {
            std::cout << "edge required: " << 0 << std::endl;
            return true;
        } 
        if(k > 4) {
            std::cout << "odd nodes > 4" << 0 << std::endl;
            return false;
        }
        if(k % 2 != 0) {
            //if the number of nodes with odd degree is odd, you cannot make these even.
            std::cout << "edges with odd  required: " << k << std::endl;
            return false;
        }    
        if(k==4) {
            //we can try to connect the odd nodes only
            int a = odd_nodes[0];
            int b = odd_nodes[1];
            int c = odd_nodes[2];
            int d = odd_nodes[3];
            if ( (adj_list[a].find(b) == adj_list[a].end()) && (adj_list[c].find(d) == adj_list[c].end()) ) {
                return true;
            }
            if ( (adj_list[a].find(c) == adj_list[a].end()) && (adj_list[b].find(d) == adj_list[b].end()) ) {
                return true;
            }
            if ( (adj_list[a].find(d) == adj_list[a].end()) && (adj_list[c].find(b) == adj_list[c].end()) ) {
                return true;
            }
            return false;
        }
        if(k==2) {
            //try to connect the odd nodes..
            //Or try to connect a single even node to both the odd nodes
            int a = odd_nodes[0];
            int b = odd_nodes[1];
            std::cout << "case k=2 " << std::endl;
            print_vector(odd_nodes);
            //the odds can connect to each other
            if (adj_list[a].find(b) == adj_list[a].end()) {
                return true;
            }
            //both the odds can connect to one of the evens
            for(int i = 1;i<=n;++i) {
                if ( (adj_list[i].find(b) == adj_list[i].end()) && (adj_list[i].find(a) == adj_list[i].end())) {
                    return true;
                }      
            }
            return false;
        }
        return false;

    }
};


int main() {


    int n = 5;
    std::vector<std::vector<int>> edges = {{1,2},{2,3},{3,4},{4,2},{1,4},{2,5}};
    Solution solv;
    bool result = solv.even_degree_of_graph(n, edges);
    std::cout << "expected true result = " << result << std::endl;
    //true

    n=7;
    edges = {{3,2},{4,5},{2,5}};
    result = solv.even_degree_of_graph(n, edges);
    std::cout << "expected true result = " << result << std::endl;
    //true

    n=15;
    edges = {{10,13},{5,6},{7,8},{1,4},{11,5},{1,3},{10,2},{11,8},{4,15},{3,13},{8,12},{10,4},{2,7},{2,11},{8,9},{12,3},{6,4},{11,10},{13,4},{4,8},{13,12},{13,1},{1,9},{11,14},{7,1},{9,15},{2,8},{9,6},{3,7},{9,5},{13,6},{5,13},{8,1},{4,3},{14,9},{4,12},{12,7},{4,11},{12,9},{15,2},{3,10},{8,13},{15,10},{10,1},{12,5},{1,6},{7,14},{10,9},{15,1},{6,15},{1,2},{6,11}};
    result = solv.even_degree_of_graph(n, edges);
    std::cout << "result = " << result << std::endl;
    

    //case II
    n = 4;
    edges = {{1,2},{3,4}};
    result = solv.even_degree_of_graph(n, edges);
    std::cout << "expected true result = " << result << std::endl;
    //true
    
    //case III
    n = 4;
    edges = {{1,2},{1,3},{1,4}};
    result = solv.even_degree_of_graph(n, edges);
    std::cout << "expected false result = " << result << std::endl;
    //false


    n = 4;
    edges = {{1,2},{2,3},{3,4}};
    result = solv.even_degree_of_graph(n, edges);
    std::cout << "expected true result = " << (bool)result << std::endl;
    //true

    return 0;
}



