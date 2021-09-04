#pragma once

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(Ice *other);
    Ice(Ice const & other);
    virtual ~Ice();
    Ice & operator=( Ice const & other );
    Ice & operator=( Ice *other );
    virtual Ice* clone() const;
    virtual void use(ICharacter& target);
};