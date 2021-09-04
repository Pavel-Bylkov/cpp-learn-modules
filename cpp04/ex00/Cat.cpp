#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat"), _name("Noname")
{
}

Cat::Cat( std::string const & name ): Animal("Cat"), _name(name)
{
}

Cat::Cat( Cat const & other )
{
    *this = other;
}

Cat::~Cat( void )
{
}

Cat & Cat::operator=( Cat const & other )
{
    if (this != &other)
    {
        this->_type = other._type;
        this->_name = other._name;
    }
    return *this;
}

void Cat::makeSound( void ) const
{
    std::cout << _type << " " << _name << " say MAYU MAYU" << std::endl;
}