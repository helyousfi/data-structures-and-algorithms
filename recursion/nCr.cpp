#include<iostream>

int ncr(int n, int r)
{
    int N=1;
    int R=1;
    int NR=1;
    for(int i=2; i<n; i++)
    {
        N*=i;
    }
    for(int i=1; i<r; i++)
    {
        R*=i;
    }
    for(int nr=1; nr<n-r; nr++)
    {
        NR*=nr; 
    }
    return N/(R*NR);
}