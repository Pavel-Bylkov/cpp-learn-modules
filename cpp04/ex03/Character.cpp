#include "Character.hpp"

Character::Character()
{
    this->_name = "Noname";
    for (int i = 0; i < 4; i++)
        this->_ms[i] = NULL;
}
    
Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; i++)
        this->_ms[i] = NULL;
}

Character::Character(Character const & other)
{
    this->_name = other.getName();

    for (int i = 0; i < 4; i++)
    {
        if (other._ms[i])
            this->_ms[i] = other._ms[i]->clone();
        else
            this->_ms[i] = NULL;
    }
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_ms[i] != NULL)
            delete this->_ms[i];
    }
}
    
Character & Character::operator=( Character const & other )
{
    if (this == &other)
        return *this;

    for (int i = 0; i < 4; i++)
    {
        if (this->_ms[i])
            delete this->_ms[i];
        this->_ms[i] = NULL;
    }
 
    this->_name = other._name;
 
    for (int i = 0; i < 4; i++)
    {
        if (other._ms[i])
            this->_ms[i] = other._ms[i]->clone();
    }
    return *this;
}

std::string const & Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (m && this->_ms[i] == NULL)
        {
            this->_ms[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
	{
        this->_ms[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4)
	{
        if (this->_ms[idx])
        {
            this->_ms[idx]->use(target);
            delete this->_ms[idx];
            this->_ms[idx] = NULL;
        }
    }
}