#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice *other) : AMateria(*other)
{
}

Ice::Ice(Ice const & other) : AMateria(other)
{
}

Ice::~Ice()
{
    std::cout << "Ice destructor\n";
}

Ice* Ice::clone() const
{
    return (new Ice(*this));
}

Ice & Ice::operator=( Ice const & other )
{
    if (this == &other)
        return *this;
 
    this->_type = other._type;
    return *this;
}

Ice & Ice::operator=( Ice *other )
{
    if (this == other)
        return *this;
 
    this->_type = other->_type;
    return *this;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
}