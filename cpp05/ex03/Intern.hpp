#pragma once

# include <iostream>
# include <exception>      // std::exception
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp" 
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
    std::string toLower(std::string const & formName) const;
    AForm* getShrubberyCreationForm(std::string const & target); 
    AForm* getRobotomyRequestForm(std::string const & target); 
    AForm* getPresidentialPardonForm(std::string const & target); 
public:
    Intern();
    Intern(Intern const & oth);
    ~Intern();
    Intern & operator=(Intern const & oth);
    AForm* makeForm(std::string const & formName, std::string const & target);
};
