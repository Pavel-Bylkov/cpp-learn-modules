#include "Fixed.hpp"

int const Fixed::_pos_of_bin_point = 8;

Fixed::Fixed( void ) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & rfs )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = rfs;
}

Fixed::Fixed( int const & n )
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = (n << Fixed::_pos_of_bin_point);
}

Fixed::Fixed( float const & n )
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = std::roundf(n * (1 << Fixed::_pos_of_bin_point));
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
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
    std::cout << "Assignation operator called" << std::endl;
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
