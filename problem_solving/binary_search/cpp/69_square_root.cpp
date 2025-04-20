/*
https://leetcode.com/problems/sqrtx/description/

use long long
*/

int my_sqrt(int x) {
    if(x < 2) {
        return x;
    }
    int l = 1;
    int r = x / 2;
    while(l <= r) {
        long long m = l + (r-l)/2;
        long long sq = m*m;
        if(sq == x) {
            return m;
        } else if(sq < x) {
            l = m + 1;
        } else {
            r = m-1;            
        }
    }
    return r;
}


int main() {
    return 0;
}