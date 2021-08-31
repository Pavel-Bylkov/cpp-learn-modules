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

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

Fixed & Fixed::operator=( Fixed const & rfs )
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rfs)
        this->_value = rfs.getRawBits();
    return *this;
}
