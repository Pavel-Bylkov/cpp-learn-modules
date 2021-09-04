#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->_ms[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._ms[i])
            this->_ms[i] = other._ms[i]->clone();
        else
            this->_ms[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor\n";
    for (int i = 0; i < 4; i++)
    {
        if (this->_ms[i] != NULL)
        {
            std::cout << this->_ms[i]->getType() << " deleted\n";
            delete this->_ms[i];
        }
    }
}

MateriaSource & MateriaSource::operator=( MateriaSource const & other )
{
    if (this == &other)
        return *this;

    for (int i = 0; i < 4; i++)
    {
        if (this->_ms[i])
            delete this->_ms[i];
        this->_ms[i] = NULL;
    }
 
    for (int i = 0; i < 4; i++)
    {
        if (other._ms[i])
            this->_ms[i] = other._ms[i]->clone();
        else
            this->_ms[i] = NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_ms[i] == NULL)
        {
            this->_ms[i] = m->clone();
            delete m;
            return ;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_ms[i] != NULL && this->_ms[i]->getType() == type)
            return this->_ms[i]->clone();
    }
    return NULL;
}