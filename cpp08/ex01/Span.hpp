#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <list>

class Span
{
public:

    Span(unsigned int const & n);
    Span(Span const & oth);
    ~Span();
    Span & operator=(Span const & oth);

    void addNumber(int const & number);
    long int shortestSpan();
    long int longestSpan();

    template<typename T> 
    void addNumber(T it_bg, T it_end)
    {
        if (_array.size() + std::distance(it_bg, it_end) > _limits)
			throw std::range_error("Error: not enough space for this range");
        for (T it = it_bg; it != it_end; ++it)
            addNumber(*it);
    }

    unsigned int size() const;
    int & operator[](long int const & index);
    const int& operator[](const long int & index) const;

private:

    std::list<int> _array;
    unsigned int _limits;

    Span();
};


std::ostream & operator<<( std::ostream & o, Span const & src);