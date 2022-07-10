#include<stdio.h>
#include<stdlib.h>
#include<iostream>

void changeValue(int* a, int x){
    *a = x;
}

int main(){
    int a = 1;
    changeValue(&a, 3);
    std::cout << a << std::endl;


    return 0;
}