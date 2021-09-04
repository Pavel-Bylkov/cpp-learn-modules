#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("Notype WrongAnimal")
{
}

WrongAnimal::WrongAnimal( std::string const & type ): _type(type)
{
}

WrongAnimal::WrongAnimal( WrongAnimal const & other )
{
    *this = other;
}

WrongAnimal::~WrongAnimal( void )
{
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & other )
{
    if (this != &other)
        this->_type = other._type;
    return *this;
}

std::string const & WrongAnimal::getType( void ) const
{
    return this->_type;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << _type << " " << " say default sound" << std::endl;
}