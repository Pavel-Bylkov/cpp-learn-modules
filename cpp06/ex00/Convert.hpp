#pragma once

# include <iostream>
# include <iomanip>
# include <string>    
# include <cstdio>      /* NULL */
# include <cstdlib>
# include <cerrno>
# include <limits>
# include <climits>
# include <cfloat>

class Convert
{
private:
    std::string _source;
    std::string _type;
    void checkTypeCharInt();
    void checkTypeFloatDouble();
public:
    Convert();
    Convert(std::string const & source);
    Convert(Convert const & oth);
    ~Convert();
    Convert & operator=(Convert const & oth);
    void newSource(std::string const & source);
    void convertToChar();
    void convertToInt();
    void convertToFloat();
    void convertToDouble();

    char        toChar;
    int         toInt;
    float       toFloat;
    double      toDouble;
};