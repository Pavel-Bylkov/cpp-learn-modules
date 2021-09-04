#pragma once

# include <iostream>
# include <string>
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* _ms[4];
    Character();
public:
    Character(std::string const & name);
    Character(Character const & other);
    virtual ~Character();
    Character & operator=( Character const & other );
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};