#include<iostream>


int pow(int m, int n) 
{
    if(n == 0)
        return 1;
    else
        return pow(m, n-1) * m;
}

int pow_fast(int m, int n)
{
    if(n == 0)
        return 1;
    else if(n%2 == 0)
        return pow_fast(m*m, n/2);
    else
        return m*pow_fast(m*m, (n-1)/2);
}

int main()
{
    std::cout << pow_fast(5, 2) << std::endl;
    return 0;
}