#include<math.h>

//logN
int compute_power_recursive(int num, int p)  {
    if(p == 0) {
        return 1;
    }
    if(p%2 == 0) {
        return compute_power_recursive(num, p/2)  * compute_power_recursive(num, p/2);
    } else {
        return compute_power_recursive(num, p-1)  * num;
    }
}

//use binary
//10    0   1   0   1   0
//19    1   0   0   1   1
int compute_power_iterative(int num, int p)  {
    int ans = 1;
    while(p > 0) {
        if(p & 1) {
            ans = ans * num;
        }
        num = num * num;
        p  = p >> 1;
    }
    return ans;
}