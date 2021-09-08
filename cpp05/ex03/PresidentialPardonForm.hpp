#pragma once

# include <iostream>
# include <exception>      // std::exception
# include <fstream>
# include <string>
# include <cstring>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    PresidentialPardonForm();
    PresidentialPardonForm & operator=(PresidentialPardonForm const & oth);
public:
    PresidentialPardonForm(std::string const & target);
    PresidentialPardonForm(PresidentialPardonForm const & oth);
    virtual ~PresidentialPardonForm();
    virtual void execute(Bureaucrat const & executor) const;
    virtual AForm* clone() const;
};
