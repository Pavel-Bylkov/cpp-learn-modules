#include "Fixed.hpp"

int const Fixed::_pos_of_bin_point = 8;

Fixed::Fixed( void ) : _value(0)
{
}

Fixed::Fixed( Fixed const & rfs )
{
    *this = rfs;
}

Fixed::Fixed( Fixed & rfs )
{
    *this = rfs;
}

Fixed::Fixed( int const & n )
{
    this->_value = (n << Fixed::_pos_of_bin_point);
}

Fixed::Fixed( float const & n )
{
    this->_value = (int)std::roundf(n * (1 << Fixed::_pos_of_bin_point));
}

Fixed::Fixed( double const & n )
{
    this->_value = (int)std::round(n * (1 << Fixed::_pos_of_bin_point));
}

Fixed::~Fixed( void )
{
}

int Fixed::getRawBits( void ) const
{
    return this->_value;
}

void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

Fixed & Fixed::operator=( Fixed const & rfs )
{
    if (this != &rfs)
        this->_value = rfs.getRawBits();
    return *this;
}

Fixed & Fixed::operator=( Fixed & rfs )
{
    if (this != &rfs)
        this->_value = rfs.getRawBits();
    return *this;
}

float Fixed::toFloat( void ) const
{
    return ((this->_value / (float)(1 << Fixed::_pos_of_bin_point)));
}
    
int Fixed::toInt( void ) const
{
    if (this->_value > 0)
        return (this->_value >> Fixed::_pos_of_bin_point);
    return -(-this->_value >> Fixed::_pos_of_bin_point);
}


std::ostream & operator<<( std::ostream & o, Fixed const & src)
{
    o << src.toFloat();
    return o;
}

Fixed Fixed::operator+( Fixed const & rfs ) const
{
    Fixed tmp;
    tmp._value = this->_value + rfs.getRawBits();
    return tmp;
}

Fixed Fixed::operator-( Fixed const & rfs ) const
{
    Fixed tmp;
    tmp._value = this->_value - rfs.getRawBits();
    return tmp;
} 

Fixed Fixed::operator*( Fixed const & rfs ) const
{
    return Fixed(this->toFloat() * rfs.toFloat());
}

Fixed Fixed::operator/( Fixed const & rfs ) const
{
    if (rfs.toFloat() == 0.0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        std::exit(1);
    }
    return Fixed(this->toFloat() / rfs.toFloat());
}

Fixed Fixed::operator+( Fixed & rfs ) const
{
    Fixed tmp;
    tmp._value = this->_value + rfs.getRawBits();
    return tmp;
}

Fixed Fixed::operator-( Fixed & rfs ) const
{
    Fixed tmp;
    tmp._value = this->_value - rfs.getRawBits();
    return tmp;
} 

Fixed Fixed::operator*( Fixed & rfs ) const
{
    return Fixed(this->toFloat() * rfs.toFloat());
}

Fixed Fixed::operator/( Fixed & rfs ) const
{
    if (rfs.toFloat() == 0.0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        std::exit(1);
    }
    return Fixed(this->toFloat() / rfs.toFloat());
}

bool Fixed::operator>( Fixed const & rfs ) const
{
    return (this->_value > rfs.getRawBits());
}

bool Fixed::operator<( Fixed const & rfs ) const
{
    return (this->_value < rfs.getRawBits());
} 

bool Fixed::operator>=( Fixed const & rfs ) const
{
    return (this->_value >= rfs.getRawBits());
}

bool Fixed::operator<=( Fixed const & rfs ) const
{
    return (this->_value <= rfs.getRawBits());
}

bool Fixed::operator==( Fixed const & rfs ) const
{
    return (this->_value == rfs.getRawBits());
}

bool Fixed::operator!=( Fixed const & rfs ) const
{
    return (this->_value != rfs.getRawBits());
}

Fixed& Fixed::operator++()
{
   _value++;
   return *this;
}

Fixed Fixed::operator++(int)
{
   Fixed temp = *this;
   ++(*this);
   return temp;
}

Fixed& Fixed::operator--()
{
   _value--;
   return *this;
}

Fixed Fixed::operator--(int)
{
   Fixed temp = *this;
   --(*this);
   return temp;
}

Fixed & Fixed::min(Fixed & a, Fixed & b)
{
    if (a <= b)
        return a;
    return b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
    if (a <= b)
        return a;
    return b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
    if (a >= b)
        return a;
    return b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
    if (a >= b)
        return a;
    return b;
}