#include<iostream>

// For loop O(n)
int fibonacci_for(int n)
{
    int t0 = 0, t1 = 1, S;
    if(n<=1)
        return n;
    for(int i=2; i<n; i++) 
    {
        S = t0 + t1;
        t0 = t1;
        t1 = S;
    }
    return S;
}

// Recursive : complexity O(2^n)
int fibonacci(int n)
{
    if(n <= 1)
        return n;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

// Recursion & memorisation : complexity O(n)
int F[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int fibonacci2(int n)
{
    if(n <= 1)
    {
        F[n] = n;
        return n;
    }
    if(F[n-2] == -1)
        F[n-2] = fibonacci2(n-2);
    if(F[n-1] == -1)
        F[n-1] = fibonacci2(n-1);
    return F[n-2] + F[n-1];
}

int main()
{
    std::cout << fibonacci_for(8) << std::endl;
    int i = 0;
    while(i<10)
    {
        std::cout << F[i] << std::endl;
        i++;
    }
    return 0;
}