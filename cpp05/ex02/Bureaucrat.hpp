#pragma once

# include <iostream>
# include <exception>      // std::exception

class AForm;

class Bureaucrat
{
protected:
    std::string const _name;
    int               _grade; // range 1 (highest possible) - 150 (lowest possible)
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    void _checkGrade( int grade ) const;
    Bureaucrat();
    Bureaucrat & operator=(Bureaucrat const & oth);
public:
    Bureaucrat(std::string const & name, int const & grade);
    Bureaucrat(Bureaucrat const & oth);
    ~Bureaucrat();
    std::string const & getName() const;
    int getGrade() const;
    void incrGrade();
    void decrGrade();
    void signForm(AForm & form);
    void executeForm(AForm const & form);
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & some);