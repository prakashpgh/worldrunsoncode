#include<iostream>

using namespace std;

//recursion
//0,1,1,2,3,5,8,13

//exponential
int fib_recursion(int n) 
{
    if(n < 2)
    {
        return n;
    }
    return fib_recursion(n-1) + fib_recursion(n-2);
}

int* memoi = nullptr;

int fib_memoi(int n) 
{
    if(memoi[n] == -1)
    {
        if(n < 2)
        {
            memoi[n] = n;    
            //std::cout << "n: " << n << "memoi: " << memoi[n];
            return n;
        }
        
        int ret = fib_memoi(n-1) + fib_memoi(n-2);
        memoi[n] = ret;
        //std::cout << "n: " << n << " memoi: " << memoi[n];
    }

    return memoi[n];
}


int fib_bottom_up(int n)
{
    int array[n+1]; // 0 to N = N+1
    array[0] = 0;
    array[1] = 1;

    for(int index = 2; index < n+1; ++index)
    {
        array[index] = array[index - 1] + array[index-2];
    }

    return array[n];
}


int main()
{
    std::cout << "fibonacci recursion " << std::endl;
    int ans = fib_recursion(7);
    std::cout << ans << std::endl;

    int n = 8;
    memoi = new int [n];
    for(auto i = 0; i < n; ++i)
    {
        memoi[i] = -1;
    }
    ans = fib_memoi(n-1);
    std::cout << " memoi: " << ans << std::endl;

    //fib bottom up
    ans = fib_bottom_up(n-1);
    std::cout << " bottom-up: " << ans << std::endl;

}



