#include "ABC.hpp"

Base* generate(void)
{
    int number;
    number = std::rand() % 3 + 1; // generate secret number between 1 and 3
    switch (number)
    {
    case 1:
        return (new A());
    case 2:
        return (new B());
    case 3:
        return (new C());
    default:
        return NULL;
    }
}

void identify(Base* p)
{
    if (p == NULL)
        return;
    A *chA = dynamic_cast<A*>(p); 
    B *chB = dynamic_cast<B*>(p);
    C *chC = dynamic_cast<C*>(p);
    if (chA) 
        std::cout << "A\n";
    else if (chB)
        std::cout << "B\n";
    else if (chC) 
        std::cout << "C\n";
    else
        std::cout << "The class of the Child is not identifer\n";
}

void identify(Base& p)
{
    if ((void *)&p == NULL)
        return;
    try
    {
        A &chA = dynamic_cast<A &>(p);
        std::cout << "A\n";
    }
    catch(const std::exception&)
    {
        try
        {
            B &chB = dynamic_cast<B &>(p);
            std::cout << "B\n";
        }
        catch(const std::exception&)
        {
            try
            {
                C &chC = dynamic_cast<C &>(p);
                std::cout << "C\n";
            }
            catch(const std::exception&)
            {
                std::cout << "The class of the Child is not identifer\n";
            }
        }
    }
}