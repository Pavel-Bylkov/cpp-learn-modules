#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
public:
    Array<T>();
    Array<T>(unsigned int const & n);
    Array<T>(Array<T> const & oth);
    ~Array<T>();
    Array<T> & operator=(Array<T> const & oth);
    T & operator[](long int const & index);
    const T& operator[](const long int & index) const;
    unsigned int size() const;
private:
    T *_array;
    unsigned int _limits;
};

template<typename T>
Array<T>::Array() 
{
    _array = NULL;
    _limits = 0;
}

template<typename T>
Array<T>::Array(unsigned int const & n)
{
    _array = new T[n];
    for (int i = 0; i < n; i++)
        _array[i] = 0;
    _limits = n;
}

template<typename T>
Array<T>::Array(Array<T> const & oth) 
{
    _limits = oth._limits;
    if (oth._array)
    {
        _array = new T[_limits];
        for (int i = 0; i < _limits; i++)
            _array[i] = oth[i];
    }
}

template<typename T>
Array<T>::~Array() 
{
    if (_array)
        delete [] _array;
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & oth) 
{
    if (this == &oth)
        return *this;
    if (_array)
        delete [] _array;
    _limits = oth._limits;
    if (oth._array)
    {
        _array = new T[_limits];
        for (int i = 0; i < _limits; i++)
            _array[i] = oth[i];
    }
    return *this;
}

template<typename T>
T & Array<T>::operator[](long int const & index) 
{
    if (index < _limits && index >= 0)
        return _array[index];
    throw std::range_error("Error: index out of range.");
}

template<typename T>
const T& Array<T>::operator[](const long int & index) const 
{
    if (index < _limits && index >= 0)
        return _array[index];
    throw std::range_error("Error: index out of range.");
}

template<typename T>
unsigned int Array<T>::size() const 
{
    return _limits;
}