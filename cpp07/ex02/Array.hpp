#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
public:
    Array();
    Array(unsigned int const & n);
    Array(Array const & oth);
    ~Array();
    Array & operator=(Array const & oth);
    T & operator[](long int const & index);
    const T& operator[](const long int & index) const;
    unsigned int size() const;
private:
    T *_array;
    unsigned int _limits;
};

#include "Array.inl"