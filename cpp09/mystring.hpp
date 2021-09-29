#pragma once

#include <iostream>
#include <cstring>
#include <cstddef> // size_t
#include <cassert>

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();

    String(const String &other);
    String &operator=(const String &other);

    struct Proxy {
        Proxy(char *str, int size, int first) : _str(str), _size(size), _first(first) { }
        Proxy(const char *str, int size, int first) : _str((char *)str), _size(size), _first(first) { }
        String operator[](int index) {
            assert(index >= 0 && index <= (int)_size);
            int new_size = index - _first;
            char *new_str = new char[new_size + 1];
            new_str[new_size] = '\0';
            while (--new_size >= 0)
                new_str[new_size] = _str[--index];
            String tmp(new_str);
            delete [] new_str;
            return String(tmp);
        }

        size_t _size;
        int _first;
	    char *_str;
    };

    Proxy operator[](int index) {
        assert(index >= 0 && index <= (int)_size);
        return Proxy(_str, _size, index);
    }

    Proxy operator[](int index) const {
        assert(index >= 0 && index <= (int)_size);
        return Proxy(_str, _size, index);
    }

	void append(const String &other);

	size_t _size;
	char *_str;
};

std::ostream & operator<<( std::ostream & o, String const & str);

class ArrayOfArrays {
public:
    ArrayOfArrays() {
        _arrayofarrays = new int*[10];
        for(int i = 0; i < 10; ++i)
            _arrayofarrays[i] = new int[10]();
    }
    ~ArrayOfArrays() {
        for(int i = 0; i < 10; ++i)
           delete [] _arrayofarrays[i];
        delete [] _arrayofarrays;
    }
    class Proxy {
    public:
        Proxy(int* _array) : _array(_array) { }

        int& operator[](int index) {
            return _array[index];
        }
    private:
        int* _array;
    };

    Proxy operator[](int index) {
        return Proxy(_arrayofarrays[index]);
    }

private:
    int** _arrayofarrays;
};


/* более элегантное решение
struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();

    String(const String &other);
    String &operator=(const String &other);

	void append(const String &other);

    struct SubStr;
    SubStr operator[](size_t i) const;

	size_t size;
	char *str;
};

struct String::SubStr
{
    SubStr(const String& s, size_t shft) : sub(s), shift(shft) {}

    String operator[](size_t i)
    {
        sub.str[i - shift] = 0;
        return String(sub.str);
    }

    String sub;
    size_t shift;
};

String::SubStr String::operator[](size_t i) const
{
    return String::SubStr(String(str + i), i);
}
*/