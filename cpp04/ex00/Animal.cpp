#include "Animal.hpp"

Animal::Animal( void ) : _type("Notype animal")
{
}

Animal::Animal( std::string const & type ): _type(type)
{
}

Animal::Animal( Animal const & other )
{
    *this = other;
}

Animal::~Animal( void )
{
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
    std::cout << _type << " " << " say default sound" << std::endl;
}