/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/

use bellman ford... **** use k+1 for k stops
*/

int find_cheapest_flight(int n, std::vector<std::vector<int>>& flights, int src, int dest, in k ) {
    int result = 0;
    return result;
}


int main() {
    int n = 4;//cities
    std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3;
    int k = 1;
    int result = find_cheapest_flight(n, flights, src, dst, k);
    std::cout << "find_cheapest_flight: " << result << std::endl;
}