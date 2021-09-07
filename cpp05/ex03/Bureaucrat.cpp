#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Error: Max Grade is 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Error: Min Grade is 150");
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

Bureaucrat::Bureaucrat(Bureaucrat const & oth) : _name(oth._name), _grade(oth._grade)
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

void Bureaucrat::signForm(AForm & form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signs " << form.getName() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " cannot sign " << form.getName() 
                << " because " << e.what() << '\n';
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executes " << form.getName() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " cannot executes " << form.getName() 
                << " because " << e.what() << '\n';
    }
}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & some)
{
    o << some.getName() << ", bureaucrat grade " << some.getGrade();
    return o;
}