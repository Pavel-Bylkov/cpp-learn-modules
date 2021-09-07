#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) 
            : AForm("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & oth) 
                                        : AForm(oth)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & oth)
{
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::checkExec(executor);
    std::cout << "...DRRRR ...DRRRR ...DRRRR (drilling noise)" << std::endl;
	if (getResoult())
		std::cout << this->getTarget() << " robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " robotomizing failed." << std::endl;
}

bool RobotomyRequestForm::getResoult() const
{
    static int s_value = 1; 
    ++s_value;
    return (s_value % 2 == 0);
}