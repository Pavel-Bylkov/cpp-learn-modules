#include "Span.hpp"

Span::Span() : _limits(0) {}

Span::Span(unsigned int const & n) : _limits(n) {}

Span::Span(Span const & oth)
{
    *this = oth;
}

Span::~Span() { _array.clear(); }

Span & Span::operator=(Span const & oth)
{
    if (this == &oth)
        return *this;
    _limits = oth._limits;
    _array.clear();
    _array = oth._array;
    return *this;
}

void Span::addNumber(int const & number)
{
    if (_array.size() == _limits)
        throw std::range_error("Error: array is full.");
    _array.push_back(number);
}

long int Span::shortestSpan()
{
    if (_array.size() < 2)
        throw std::range_error("Error: no span to find.");
    _array.sort();
    long int min_span = static_cast<long int>(_array.back()) - _array.front();
    std::list<int>::iterator	it2 = _array.begin();
    it2++;
    for (std::list<int>::iterator	it1 = _array.begin(); it2 != _array.end(); it1++)
    {
        if (static_cast<long int>(*it2) - *it1 < min_span)
            min_span = static_cast<long int>(*it2) - *it1;
        it2++;
    }
    return min_span;
}

long int Span::longestSpan()
{
    if (_array.size() < 2)
        throw std::range_error("Error: no span to find.");
    _array.sort();
    return (static_cast<long int>(_array.back()) - static_cast<long int>(_array.front()));
}

int& Span::operator[](long int const & index) 
{
    long int i = 0;
    if (index < _limits && index >= 0 && _array.size() > index)
    {
        std::list<int>::iterator	it = _array.begin();
        while (i++ < index)
            it++;
        return *it;
    }
        
    throw std::range_error("Error: index out of range.");
}

const int& Span::operator[](const long int & index) const 
{
    long int i = 0;
    if (index < _limits && index >= 0 && _array.size() > index)
    {
        std::list<int>::const_iterator	it = _array.begin();
        while (i++ < index)
            it++;
        return *it;
    }
    throw std::range_error("Error: index out of range.");
}

unsigned int Span::size() const 
{
    return _array.size();
}

std::ostream & operator<<( std::ostream & o, Span const & src)
{
    unsigned int s = src.size();
    if (s == 0)
        o << "Array is empty";
    else if (s <= 10)
        for (int i = 0; i < s; i++)
            o << src[i] << " ";
    else
    {
        for (int i = 0; i < 5; i++)
            o << src[i] << " ";
        o << "... ";
        for (int i = s - 5; i < s; i++)
            o << src[i] << " ";
    }
    return o;
}