#pragma once

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _ms[4];
public:
    MateriaSource();
    MateriaSource(MateriaSource const & other);
    virtual ~MateriaSource();
    MateriaSource & operator=( MateriaSource const & other );
    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};