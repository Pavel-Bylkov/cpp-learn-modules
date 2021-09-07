#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form Error: Max Grade is 1");
}

Form::GradeTooLowException::GradeTooLowException() throw() : mode(1) {}
Form::GradeTooLowException::GradeTooLowException(int mode) throw() : mode(mode) {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooLowException::what() const throw()
{
    if (mode == 1)
        return ("Form Error: Grade form less than 150");
    return ("Form Error: the grade of Bureaucrat is too low then Form");
}

Form::Form() : _name("Noname"), _isSigned(0), _gradeToSign(150), _gradeToExec(150) {}

Form::Form(std::string const & name, int const & grade1, int const & grade2) :
                        _name(name), _isSigned(0), _gradeToSign(grade1), _gradeToExec(grade2)
{
    _checkGrade(grade1);
    _checkGrade(grade2);
}

void Form::_checkGrade( int grade ) const
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const & oth) : _name(oth.getName())
                            , _isSigned(oth.getState())
                            , _gradeToSign(oth.getGradeToSign())
                            , _gradeToExec(oth.getGradeToExec())
{
}

Form::~Form()
{
}

Form & Form::operator=(Form const & oth)
{
    return *this;
}

std::string const & Form::getName() const
{
    return this->_name;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExec() const
{
    return this->_gradeToExec;
}

bool Form::getState() const
{
    return this->_isSigned;
}

void Form::beSigned(Bureaucrat const & boss)
{
    if (boss.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException(2);
    this->_isSigned = true;
}

std::ostream & operator<<( std::ostream & o, Form const & some)
{
    if (some.getState())
        o << some.getName() << " is signed";
    else
        o << some.getName() << " is not signed";
    o << ", grade to sign " << some.getGradeToSign()
		<< ", grade to execute " << some.getGradeToExec();
    return o;
}