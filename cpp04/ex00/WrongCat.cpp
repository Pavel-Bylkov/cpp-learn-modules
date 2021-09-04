#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat"), _name("Noname")
{
}

WrongCat::WrongCat( std::string const & name ): WrongAnimal("WrongCat"), _name(name)
{
}

WrongCat::WrongCat( WrongCat const & other )
{
    *this = other;
}

WrongCat::~WrongCat( void )
{
}

WrongCat & WrongCat::operator=( WrongCat const & other )
{
    if (this != &other)
    {
        this->_type = other._type;
        this->_name = other._name;
    }
    return *this;
}

void WrongCat::makeSound( void ) const
{
    std::cout << _type << " " << _name << " say MAYU MAYU" << std::endl;
}