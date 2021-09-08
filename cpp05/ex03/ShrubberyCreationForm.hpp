#pragma once

# include <iostream>
# include <exception>      // std::exception
# include <fstream>
# include <string>
# include <cstring>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string ascii_tree;
    ShrubberyCreationForm();
    ShrubberyCreationForm & operator=(ShrubberyCreationForm const & oth);
public:
    ShrubberyCreationForm(std::string const & target);
    ShrubberyCreationForm(ShrubberyCreationForm const & oth);
    virtual ~ShrubberyCreationForm();
    virtual void execute(Bureaucrat const & executor) const;
    void writeToFile(std::string const & fname, std::string const & str) const;
    virtual AForm* clone() const;
};
