#include "Convert.hpp"

Convert::Convert() : _source(""), toChar(0), toInt(0), toFloat(0), toDouble(0), _type("") {}

Convert::Convert(std::string const & source) : _source(source), _type("")
{
    checkTypeCharInt();
    checkTypeFloatDouble();
    convertToChar();
    convertToInt();
    convertToFloat();
    convertToDouble();
}

Convert::Convert(Convert const & oth)
{
    *this = oth;
}

Convert::~Convert() {}

Convert & Convert::operator=(Convert const & oth)
{
    if (this == &oth)
        return *this;
    _source = oth._source;
    _type = oth._type;
    toChar = oth.toChar;
    toInt = oth.toInt;
    toFloat = oth.toFloat;
    toDouble = oth.toDouble;
    return *this;
}

void Convert::newSource(std::string const & source)
{
    _source = source;
    _type = "";
    checkTypeCharInt();
    checkTypeFloatDouble();
    convertToChar();
    convertToInt();
    convertToFloat();
    convertToDouble();
}

void Convert::convertToChar()
{
    if (this->_type == "char")
    {
        std::cout << "char: " << this->_source << std::endl;
        return ;
    }
     
    std::cout << "char: ";
    try
    {
        if (this->_type == "float")
            this->toChar = static_cast<char>(this->toFloat);
        else if (this->_type == "double")
            this->toChar = static_cast<char>(this->toDouble);
        else if (this->_type == "int")
            this->toChar = static_cast<char>(this->toInt);
        if (this->toChar >= 0 && this->toChar <= 31 || this->toChar == 127)
            std::cout << "Non displayable";
        std::cout << this->toChar;
    }
    catch (std::exception&)
    {
        std::cout  << "impossible";
        toChar = 0;
    }
    std::cout << std::endl;
}

void Convert::convertToInt()
{
    if (this->_type == "int")
    {
        std::cout << "int: " << this->_source << std::endl;
        return ;
    }

    std::cout << "int: ";
    try
    {
        long long int ll = 0;
        if (this->_type == "float")
            ll = static_cast<long long int>(this->toFloat);
        else if (this->_type == "double")
            ll = static_cast<long long int>(this->toDouble);
        else if (this->_type == "char")
            ll = static_cast<long long int>(this->toChar);
        if (ll >= INT32_MIN && ll <= INT32_MAX)
        {
            toInt = static_cast<int>(ll);
            std::cout << toInt;
        }
        else
            std::cout << "overflow";
    }
    catch (std::exception&)
    {
        std::cout  << "impossible";
        toInt = 0;
    }
    std::cout << std::endl;
}

void Convert::convertToFloat()
{
    std::cout << "float: ";
    try
    {
        if (this->_type == "int")
            this->toFloat = static_cast<float>(this->toInt);
        else if (this->_type == "double")
            this->toFloat = static_cast<float>(this->toDouble);
        else if (this->_type == "char")
            this->toFloat = static_cast<float>(this->toChar);
        std::cout << std::fixed;
        std::cout << std::setprecision(1) << toFloat << "f"; // << std::showpoint
    }
    catch (std::exception&)
    {
        std::cout  << "impossible";
        toFloat = 0;
    }
    std::cout << std::endl;
}

void Convert::convertToDouble()
{
    std::cout << "double: ";
    try
    {
        if (this->_type == "int")
            this->toDouble = static_cast<double>(this->toInt);
        else if (this->_type == "float")
            this->toDouble = static_cast<double>(this->toFloat);
        else if (this->_type == "char")
            this->toDouble = static_cast<double>(this->toChar);
        std::cout << std::fixed;
        std::cout << std::setprecision(1) << toDouble; // << std::showpoint
    }
    catch (std::exception&)
    {
        std::cout  << "impossible";
        toDouble = 0;
    }
    std::cout << std::endl;
}

void Convert::checkTypeCharInt()
{
    int len = _source.size();
    const char *source = _source.c_str();
    char *pEnd;
    long int li;

    errno = 0;
    li = std::strtol(source, &pEnd, 10);
    if (len < 2)
    {    
        if (li != 0L || source[0] == '0')
        {
            this->toInt = static_cast<int>(li);
            this->_type = "int";
        }
        else
        {
            this->toChar = source[0];
            this->_type = "char";
        }
    }
    else if (*pEnd != '.' && *pEnd != 'i' && *pEnd != 'n' && *pEnd != '-' && *pEnd != '+')
    {
        if (errno == ERANGE || li < INT32_MIN || li > INT32_MAX)
            throw std::runtime_error("integer overflow.");
        this->toInt = static_cast<int>(li);
        this->_type = "int";
    }
}

void Convert::checkTypeFloatDouble()
{
    if (_type != "")
        return ;
    const char *source = _source.c_str();
    char* pEnd;
    double d;
    errno = 0;
    d = std::strtod(source, &pEnd);
    if (*pEnd == 'f')
    {
        if (_source == "-inff")
            this->toFloat = -std::numeric_limits<float>::infinity();
        else if (_source == "+inff")
            this->toFloat = +std::numeric_limits<float>::infinity();
        else if (errno == ERANGE || d < -FLT_MAX || d > FLT_MAX)
            throw std::runtime_error("float overflow.");
        else
            this->toFloat = static_cast<float>(d);
        this->_type = "float";
    }
    else
    {
        if (_source == "-inf")
            this->toDouble = -std::numeric_limits<double>::infinity();
        else if (_source == "+inf")
            this->toDouble = +std::numeric_limits<double>::infinity();
        else
            this->toDouble = d;
        this->_type = "double";
    }
}
