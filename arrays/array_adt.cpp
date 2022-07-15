#include<iostream>

// Define array as a structure
struct Array
{
    int *A;
    int size;
};

// Display the array
void Display(Array arr)
{
    std::cout << "The elements are :" << std::endl;
    for(int i=0; i<arr.size; i++){
        std::cout << arr.A[i] << " ";
    }
}

int main()
{
    Array arr;
    std::cout << "Enter size : " << std::endl;
    std::cin >> arr.size;
    arr.A = new int[arr.size];

    std::cout << "Enter all elements : " << std::endl;
    for(int i=0; i<arr.size; i++){
        std::cin >> arr.A[i];
    }

    Display(arr);
    return 0;
}
