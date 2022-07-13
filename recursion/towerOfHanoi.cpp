#include<iostream>

void towerOfHanoi(int n, int A, int B, int C)
{
    if(n>0)
    {
        towerOfHanoi(n-1, A, C, B);
        std::cout << "Move from " << A << " to " << C << std::endl;
        towerOfHanoi(n-1, B, A, C);
    }
}
int main()
{
    towerOfHanoi(4, 1, 2, 3);
    return 0;
}