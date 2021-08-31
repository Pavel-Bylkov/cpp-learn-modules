#include "Karen.hpp"

unsigned long long s::hash(const char *s1)
{
    unsigned long long hash = 5381;
    int c;

    while ((c = *s1++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c 

    return hash;
}

void Karen::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love to get extra bacon for my ";
    std::cout << "7XL-double-cheese-triple-pickle-special";
    std::cout << "-ketchup burger.  I just love it!";
    std::cout << std::endl << std::endl;
}

void Karen::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon ";
    std::cout << "cost more money. \nYou don’t put enough! ";
    std::cout << "If you did I would not have to ask for it!";
    std::cout << std::endl << std::endl;
}
    
void Karen::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon ";
    std::cout << "for free. \nI’ve been coming here for years ";
    std::cout << "and you just started working here last month.";
    std::cout << std::endl << std::endl;
}

void Karen::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now.";
    std::cout << std::endl << std::endl;
}

void Karen::complain( s::str level )
{
    void (Karen::*memfunc_ptr[4])(void) = {&Karen::debug,
                                        &Karen::info,
                                        &Karen::warning,
                                        &Karen::error};
    s::str levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i])
        {
            (this->*memfunc_ptr[i])();
            return;
        }
    }
    std::cout << "I don't now this level!" << std::endl;
}