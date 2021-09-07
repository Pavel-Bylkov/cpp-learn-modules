#pragma once

# include <iostream>
# include <exception>      // std::exception
# include <fstream>
# include <string>
# include <cstring>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    RobotomyRequestForm();
    RobotomyRequestForm & operator=(RobotomyRequestForm const & oth);
    bool getResoult() const;
public:
    RobotomyRequestForm(std::string const & target);
    RobotomyRequestForm(RobotomyRequestForm const & oth);
    virtual ~RobotomyRequestForm();
    virtual void execute(Bureaucrat const & executor) const;
};
