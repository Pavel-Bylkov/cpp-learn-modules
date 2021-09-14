#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <vector>
#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(-2147483648);
    sp.addNumber(3);
    sp.addNumber(2147483647);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    try
    {
        sp.addNumber(11);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Span				sp2 = Span(20000);
	std::vector<int>	vec(20001);
	std::srand(std::time(NULL));
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		*it = rand() % 500 - 250;
	try
    {
        sp2.addNumber(vec.begin(), vec.end());
    }
	catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl; 
    }
    try
    {
        std::cout << sp2 << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << sp2.longestSpan() << std::endl;
    }
	catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl; 
    }

    return 0;
}