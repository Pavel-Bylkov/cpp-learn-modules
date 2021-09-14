#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"


int main()
{
    std::vector<int> array1;
    std::deque<int> array2;
    std::list<int> array3;

    std::cout << "------- test replace for vector -----------" << std::endl;
    genArray(array1, 12);
    std::cout << "------- right -----------" << std::endl;
    replace(array1, 5, 555);
    std::cout << "------- wrong -----------" << std::endl;
    replace(array1, 55, 333);
    
    std::cout << "\n------- test replace for deque -----------" << std::endl;
    genArray(array2, 20);
    std::cout << "------- right -----------" << std::endl;
    replace(array2, 3, 222);
    std::cout << "------- wrong -----------" << std::endl;
    replace(array2, 55, 333);

    std::cout << "\n------- test replace for list -----------" << std::endl;
    genArray(array3, 20);
    std::cout << "------- right -----------" << std::endl;
    replace(array3, 9, 666);
    std::cout << "------- wrong -----------" << std::endl;
    replace(array3, 55, 333);

    return 0;
}