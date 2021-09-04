#include "Animal.hpp"

Animal::Animal( void ) : _type("Notype animal")
{
    std::cout << "Animal\tdefault constructor called" << std::endl;
}

Animal::Animal( std::string const & type ): _type(type)
{
    std::cout << "Animal\tconstructor called for " << _type << std::endl;
}

Animal::Animal( Animal const & other )
{
    *this = other;
}

Animal::~Animal( void )
{
    std::cout << "Animal\tdestructor called for " << _type << std::endl;
}

Animal & Animal::operator=( Animal const & other )
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

std::string const & Animal::getType( void ) const
{
    return this->_type;
}

void Animal::makeSound( void ) const
{
    std::cout << _type << "\t" << " say ???" << std::endl;
}