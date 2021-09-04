#pragma once

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure( Cure *other );
    Cure( Cure const & other );
    virtual ~Cure();
    Cure & operator=( Cure const & other );
    Cure & operator=( Cure *other );
    virtual Cure* clone() const;
    virtual void use( ICharacter& target );
};