
template<typename T>
inline Array<T>::Array() 
{
    _array = NULL;
    _limits = 0;
}

template<typename T>
inline Array<T>::Array(unsigned int const & n)
{
    _array = new T[n];
    for (int i = 0; i < n; i++)
        _array[i] = 0;
    _limits = n;
}

template<typename T>
inline Array<T>::Array(Array<T> const & oth) 
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
inline Array<T>::~Array() 
{
    if (_array)
        delete [] _array;
}

template<typename T>
inline Array<T> & Array<T>::operator=(Array<T> const & oth) 
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
inline T & Array<T>::operator[](long int const & index) 
{
    if (index < _limits && index >= 0)
        return _array[index];
    throw std::range_error("Error: index out of range.");
}

template<typename T>
inline const T& Array<T>::operator[](const long int & index) const 
{
    if (index < _limits && index >= 0)
        return _array[index];
    throw std::range_error("Error: index out of range.");
}

template<typename T>
inline unsigned int Array<T>::size() const 
{
    return _limits;
}