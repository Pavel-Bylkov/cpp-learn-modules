#include "Bureaucrat.hpp"
#include "Intern.hpp"

typedef AForm Form;

int main ()
{
    Bureaucrat boss[3] = {
            Bureaucrat("Boss1", 1),
            Bureaucrat("Boss2", 45),
            Bureaucrat("Boss3", 148)};
    Intern someRandomIntern;
    Form* rrf;

    std::cout << "\n------- Test mistake form ---------\n";
    rrf = someRandomIntern.makeForm("new form", "Something");
    
    Form *forms[3] = {someRandomIntern.makeForm("robotomy request", "Bender"),
                     someRandomIntern.makeForm("shrubbery creation", "Home"),
                     someRandomIntern.makeForm("presidential pardon", "Barbara")};
    
    std::cout << "\n------- Test normal forms ---------\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "\n----- loop for i = " << i << " j = " << j << " -----\n"; 
            std::cout << boss[i] << std::endl;
            rrf = forms[j]->clone(); 
            std::cout << *rrf << " get\n";
            try
            {
                boss[i].signForm(*rrf);
                boss[i].executeForm(*rrf);
            }
            catch (std::exception& e)
            {
                std::cerr << "exception caught: " << e.what() << '\n';
            }
            delete rrf;
        }
    }

    for (int i = 0; i < 3; i++)
        delete forms[i];

    return 0;
}