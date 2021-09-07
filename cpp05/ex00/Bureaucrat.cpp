#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat Error: Max Grade is 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat Error: Min Grade is 150");
}

Bureaucrat::Bureaucrat() : _name("Noname"), _grade(150) {}
Bureaucrat::Bureaucrat(std::string const & name, int const & grade) :
                                        _name(name)
{
    _checkGrade(grade);
    _grade = grade;
}

void Bureaucrat::_checkGrade( int grade ) const
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const & oth) : _name(oth.getName())
                                            , _grade(oth.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & oth)
{
    return *this;
}

std::string const & Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrGrade()
{
    _checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrGrade()
{
    _checkGrade(_grade + 1);
    _grade++;
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & some)
{
    o << some.getName() << ", bureaucrat grade " << some.getGrade();
    return o;
}