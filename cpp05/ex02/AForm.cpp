#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Form Error: Max Grade is 1");
}

AForm::GradeTooLowException::GradeTooLowException() throw() : mode(1) {}
AForm::GradeTooLowException::GradeTooLowException(int mode) throw() : mode(mode) {}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char* AForm::GradeTooLowException::what() const throw()
{
    if (mode == 1)
        return ("Form Error: Grade AForm less than 150");
    return ("Form Error: the grade of Bureaucrat is too low then AForm");
}

const char* AForm::SignedException::what() const throw()
{
    return ("Form Error: Form is not signed");
}

AForm::AForm() : _name("Noname"), _isSigned(0), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(std::string const & name, int const & sign, int const & exec, std::string const & target) :
                        _name(name), _isSigned(0), _gradeToSign(sign), _gradeToExec(exec), _target(target)
{
    _checkGrade(sign);
    _checkGrade(exec);
}

void AForm::_checkGrade( int grade ) const
{
    if (grade < 1)
        throw AForm::GradeTooHighException();
    if (grade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & oth) : _name(oth.getName())
                            , _isSigned(oth.getState())
                            , _gradeToSign(oth.getGradeToSign())
                            , _gradeToExec(oth.getGradeToExec())
{
}

AForm::~AForm()
{
}

AForm & AForm::operator=(AForm const & oth)
{
    return *this;
}

std::string const & AForm::getName() const
{
    return this->_name;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExec() const
{
    return this->_gradeToExec;
}

bool AForm::getState() const
{
    return this->_isSigned;
}

std::string const & AForm::getTarget() const
{
    return this->_target;
}

void AForm::beSigned(Bureaucrat const & boss)
{
    if (boss.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException(2);
    this->_isSigned = true;
}

void AForm::checkExec(Bureaucrat const & executor) const
{
    if (!this->_isSigned)
        throw AForm::SignedException();
    if (executor.getGrade() > this->_gradeToExec)
        throw AForm::GradeTooLowException(2);
}

std::ostream & operator<<( std::ostream & o, AForm const & some)
{
    if (some.getState())
        o << some.getName() << " is signed";
    else
        o << some.getName() << " is not signed";
    o << ", grade to sign " << some.getGradeToSign()
		<< ", grade to execute " << some.getGradeToExec();
    return o;
}