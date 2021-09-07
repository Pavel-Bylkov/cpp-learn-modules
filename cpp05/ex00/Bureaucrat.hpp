#pragma once

# include <iostream>
# include <exception>      // std::exception

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
    Bureaucrat(Bureaucrat const & oth);
    Bureaucrat & operator=(Bureaucrat const & oth);
public:
    Bureaucrat(std::string const & name, int const & grade);
    ~Bureaucrat();
    std::string const & getName() const;
    int getGrade() const;
    void incrGrade();
    void decrGrade();
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & some);