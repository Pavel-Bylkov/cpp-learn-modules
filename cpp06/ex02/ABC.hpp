#pragma once

# include <cstdlib>     /* srand, rand */
# include <ctime>       /* time */
# include <cstdio> 
# include "Base.hpp"

class A: public Base
{
};

class B: public Base
{
};

class C: public Base
{
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);