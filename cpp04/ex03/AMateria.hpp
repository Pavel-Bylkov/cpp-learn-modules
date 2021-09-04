#pragma once

# include "ICharacter.hpp"

class AMateria
{
protected:
    std::string _type;
public:
    AMateria(std::string const & type);
    AMateria(AMateria const & other);
    AMateria(AMateria *other);
    AMateria();
    virtual ~AMateria();
    AMateria & operator=( AMateria const & other );
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};