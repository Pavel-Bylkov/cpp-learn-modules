#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp" 
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    Bureaucrat boss[3] = {
            Bureaucrat("Boss1", 1),
            Bureaucrat("Boss2", 45),
            Bureaucrat("Boss3", 148)};

    ShrubberyCreationForm form1("home");
    std::cout << form1 << " get\n";
    RobotomyRequestForm form2("steel");
    std::cout << form2 << " get\n";
    PresidentialPardonForm form3("Barbara");
    std::cout << form3 << " get\n";

    AForm *forms[3] = {&form1, &form2, &form3};
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "\n----- loop for i = " << i << " j = " << j << " -----\n"; 
            std::cout << boss[i] << std::endl;
            try
            {
                boss[i].signForm(*forms[j]);
                boss[i].executeForm(*forms[j]);
            }
            catch (std::exception& e)
            {
                std::cerr << "exception caught: " << e.what() << '\n';
            }
        }
    }

    boss[0].executeForm(*forms[1]);
    boss[0].executeForm(*forms[1]);
    boss[0].executeForm(*forms[1]);
    boss[0].executeForm(*forms[1]);

    return 0;
}