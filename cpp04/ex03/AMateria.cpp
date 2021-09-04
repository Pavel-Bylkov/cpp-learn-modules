#include "AMateria.hpp"

AMateria::AMateria(): _type("nontype"){}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(AMateria const & other) : _type(other._type)
{
}

AMateria::AMateria(AMateria *other) : _type(other->_type)
{
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=( AMateria const & other )
{
    if (this == &other)
        return *this;
 
    this->_type = other._type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}