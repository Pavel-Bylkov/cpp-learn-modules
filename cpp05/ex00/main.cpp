#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat *sheff1;
    Bureaucrat *sheff2;
    Bureaucrat *sheff3;
    try
    {
        sheff1 = new Bureaucrat("Boss1", 148);
        std::cout << *sheff1 << " start\n";
    }
    catch (std::exception& e)
    {
        std::cerr << "exception caught: " << e.what() << '\n';
        sheff1 = 0;
    }
    try
    {
        sheff2 = new Bureaucrat("Boss2", 3);
        std::cout << *sheff2 << " start\n";
    }
    catch (std::exception& e)
    {
        std::cerr << "exception caught: " << e.what() << '\n';
        sheff2 = 0;
    }
    try
    {
        sheff3 = new Bureaucrat("Boss3", 250);
        std::cout << *sheff3 << " start\n";
    }
    catch (std::exception& e)
    {
        std::cerr << "exception caught: " << e.what() << '\n';
        sheff3 = 0;
    }
    try
    {
        for (int i = 0; i < 4; i++)
        {
            sheff1->decrGrade();
            std::cout << *sheff1 << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cerr << *sheff1 << " exception caught: " << e.what() << '\n';
    }
    try
    {
        for (int i = 0; i < 4; i++)
        {
            sheff2->incrGrade();
            std::cout << *sheff2 << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cerr << *sheff2 << " exception caught: " << e.what() << '\n';
    }
    if (sheff1)
        delete sheff1;
    if (sheff2)
        delete sheff2;
    if (sheff3)
        delete sheff3;
    return 0;
}