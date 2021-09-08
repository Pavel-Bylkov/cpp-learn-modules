#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern() 
{
}

Intern::Intern(Intern const & oth)
{
    *this = oth;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const & oth)
{
    return *this;
}

std::string Intern::toLower(std::string const & formName) const
{
    std::string str = formName;

    for (unsigned long i = 0; i < str.size(); i++)
        str.replace(i, 1, 1, (char)std::tolower(str[i]));
    return str.substr();
}

AForm* Intern::getShrubberyCreationForm(std::string const & target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::getRobotomyRequestForm(std::string const & target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::getPresidentialPardonForm(std::string const & target)
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string const & formName, std::string const & target)
{
    AForm * res;
    AForm* (Intern::*func_ptr[3])(std::string const &) = {
                        &Intern::getShrubberyCreationForm,
                        &Intern::getRobotomyRequestForm,
                        &Intern::getPresidentialPardonForm};
    std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

    std::string tmp = toLower(formName);

    for (int i = 0; i < 3; ++i)
    {
        try
        {
            if (forms[i] == tmp)
            {
                res = (this->*func_ptr[i])(target);
                std::cout << "Intern creates " << *res << std::endl;
                return res;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr <<  "Intern cannot create " << formName << " for " << target
                    << " because " << e.what() << '\n';
            return NULL;
        }
    }
    std::cerr << "I don't now this form!" << std::endl;
    return NULL;
}
