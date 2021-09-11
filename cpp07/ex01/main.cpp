#include <iostream>
#include "iter.hpp"

template<typename T>
void printItem(T& item)
{
    std::cout << item << ", ";
}

int main()
{
    int array1[5] = {1, 2, 3, 4, 5};
    float array2[5] = {1.1, 22.2, 3.3, 44.4, 5.5};
    
    std::cout << "int array:\n";
    iter(array1, 5, printItem);
    std::cout << "\nfloat array:\n";
    iter(array2, 5, printItem);
    std::cout << std::endl;
    
    return 0;
}