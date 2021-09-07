#pragma once

# include <iostream>
# include <exception>      // std::exception
# include "Bureaucrat.hpp"

class Form
{
private:
    std::string const _name;
    bool          _isSigned;
    int const  _gradeToSign; // range 1 (highest possible) - 150 (lowest possible)
    int const  _gradeToExec;
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
    void _checkGrade( int grade ) const;
    Form();
    Form & operator=(Form const & oth);
public:
    Form(std::string const & name, int const & grade1, int const & grade2);
    Form(Form const & oth);
    ~Form();
    std::string const & getName() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    bool getState() const;
    void beSigned(Bureaucrat const & boss);
};

std::ostream & operator<<( std::ostream & o, Form const & some);