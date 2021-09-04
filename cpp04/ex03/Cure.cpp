#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure *other) : AMateria(*other)
{
}

Cure::Cure(Cure const & other) : AMateria(other)
{
}

Cure::~Cure()
{
    std::cout << "Cure destructor\n";
}

Cure* Cure::clone() const
{
    return (new Cure(*this));
}

Cure & Cure::operator=( Cure const & other )
{
    if (this == &other)
        return *this;
 
    this->_type = other.getType();
    return *this;
}

Cure & Cure::operator=( Cure *other )
{
    if (this == other)
        return *this;
 
    this->_type = other->getType();
    return *this;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
}