#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog"), _name("Noname")
{
}

Dog::Dog( std::string const & name ): Animal("Dog"), _name(name)
{
}

Dog::Dog( Dog const & other )
{
    *this = other;
}

Dog::~Dog( void )
{
}

Dog & Dog::operator=( Dog const & other )
{
    if (this != &other)
    {
        this->_type = other._type;
        this->_name = other._name;
    }
    return *this;
}

void Dog::makeSound( void ) const
{
    std::cout << _type << " " << _name << " say GAV GAV" << std::endl;
}