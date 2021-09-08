#pragma once

# include <iostream>
# include <exception>      // std::exception
# include "Bureaucrat.hpp"

class AForm
{
private:
    std::string const   _name;
    bool            _isSigned;
    int const    _gradeToSign; // range 1 (highest possible) - 150 (lowest possible)
    int const    _gradeToExec;
    std::string const _target;
protected:
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        int mode;
        GradeTooLowException () throw();
        GradeTooLowException (int mode) throw();
        virtual ~GradeTooLowException() throw();
        virtual const char* what() const throw();
    };
    class SignedException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    void _checkGrade( int grade ) const;
    AForm();
    AForm & operator=(AForm const & oth);
public:
    AForm(std::string const & name, int const & sign, int const & exec, std::string const & target);
    AForm(AForm const & oth);
    virtual ~AForm();
    std::string const & getName() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    bool getState() const;
    std::string const & getTarget() const;
    void beSigned(Bureaucrat const & boss);
    void checkExec(Bureaucrat const & executor) const;
    virtual void execute(Bureaucrat const & executor) const = 0;
    virtual AForm* clone() const = 0;
};

std::ostream & operator<<( std::ostream & o, AForm const & some);