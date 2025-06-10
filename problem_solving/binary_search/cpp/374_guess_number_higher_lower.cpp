'''
https://leetcode.com/problems/guess-number-higher-or-lower/

classical binary search problem

'''
int guess(int num) {
    return 0;
}

int guess_number(int n) {
    int l = 1;
    int r = n;
    while(l < r)  {
        int m = l + (r-l)/2;
        int g = guess(m);
        if( g == 0) {
            return m;
        } else if (g == -1) {
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return l;
}