#pragma once

#include <deque> 
#include <stack> 

template< typename T, class Container=std::deque<T> >
class MutantStack : public std::stack< T, Container >
{
public:
    typedef typename Container::iterator iterator;
    
    MutantStack() : std::stack< T, Container >() {}
    MutantStack(MutantStack const & oth) : std::stack< T, Container >(oth) {}
    ~MutantStack() {}

    MutantStack & operator=(MutantStack const & oth)
    {
        this->c = oth.c;
        return *this;
    }

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};


// template<typename T>
// class MutantStack : public std::deque<T>
// {
// public:
//     T & top() // Access to last element
//     {
//         return std::deque<T>::back();
//     }
//     void push( T const & x) // Insert element
//     {
//         std::deque<T>::push_back(x);
//     }
//     void pop() // delete last element
//     {
//         std::deque<T>::pop_back();
//     }
// };
