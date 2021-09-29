#include "mystring.hpp"

String::String(const char *str)
{
    int size = std::strlen(str);
    _size = size;
	_str = new char[_size + 1];
    _str[size] = '\0';
    while (--size >= 0)
        _str[size] = str[size];
}
	
String::String(size_t n, char c)
{
    _size = n;
    int size = n;
	_str = new char[_size + 1];
    _str[size] = '\0';
    while (--size >= 0)
        _str[size] = c;
}

String::~String()
{
    delete [] _str;
}

String::String(const String &other)
{
    _size = other._size;
    int new_size = _size;
    _str = new char[new_size + 1];
    _str[new_size] = '\0';
    while (--new_size >= 0)
        _str[new_size] = other._str[new_size];
}

String & String::operator=(const String &other)
{
    if (this == &other)
        return *this;
    _size = other._size;
    int new_size = _size;
    delete [] _str;
    _str = new char[new_size + 1];
    _str[new_size] = '\0';
    while (--new_size >= 0)
        _str[new_size] = other._str[new_size];
    return *this;
}

void String::append(const String &other)
{
    int other_size = other._size;
    int new_size = _size + other_size;
    char *new_str = new char[new_size + 1];
    new_str[new_size] = '\0';
    while (--other_size >= 0)
        new_str[--new_size] = other._str[other_size];
    while (--new_size >= 0)
        new_str[new_size] = _str[new_size];
    _size += other._size;
    delete [] _str;
    _str = new_str;
}

std::ostream & operator<<( std::ostream & o, String const & str)
{
    o << str._str;
    return o;
}