#pragma once

#include <stdexcept>
#include <algorithm>

template <class T>
int & easyfind(T &array, int search)
{
	typename T::iterator	it = std::find(array.begin(), array.end(), search);
	if (it == array.end())
		throw std::runtime_error("Not found current value in conteiner");
    std::cout << "It's found on pos # "
				<< std::distance(array.begin(), it) + 1 << std::endl;
	return (*it);
}

// template<class T> 
// int & easyfind(T & array, int search)
// {
//     for (int& value : array)
//     {
//         if (value == search)
//             return value;
//     }
//     throw std::runtime_error("Not found current value in conteiner");
// }

template<class T> 
void replace(T & array, int search, int newValue)
{
    try
    {
        int &find = easyfind(array, search);
        std::cout << "Yes, i find - " << find << std::endl;
        find = newValue;
        for (int& value : array) std::cout << value << " ";
        std::cout <<  std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

template<class T> 
void genArray(T & array, int size)
{
    for (int i = -size / 2; i < size / 2; i++) 
    {
        array.push_back(i);
        std::cout << i << " ";
    }
    std::cout << std::endl;
}