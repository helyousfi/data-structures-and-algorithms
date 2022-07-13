// Tyalor series with static variables
#include<iostream>

int e(int x, int n)
{
    int r;
    static int p = 1, f = 1;
    if (n == 0)
        return 1;
    else
        r = e(x, n-1);
        p = p * x;
        f = f * n;
        return r + p/f;
}

int e_fast(int x, int n)
{
    static int S = 1;
    if(n == 0)
        return S;
    S = 1 + x/n * S;
    return e_fast(x, n-1);
}

int e_fast2(int x, int n)
{
    int S = 1;
    for(int i=n; i > 0; i--){
        S = 1 + x/i * S;
    }
    return S;
}


int main()
{
    std::cout << e_fast2(4, 2) << std::endl;
    return 0;
}