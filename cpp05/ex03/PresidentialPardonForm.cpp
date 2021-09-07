#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) 
            : AForm("PresidentialPardonForm", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & oth) 
                                        : AForm(oth)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & oth)
{
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::checkExec(executor);
    std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
