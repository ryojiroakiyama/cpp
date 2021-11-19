#include "Form.hpp"

Form::Form( std::string name, int sgrade, int egrade , std::string target)
: _Name(name)
, _isSigned(false)
, _SignGrade(sgrade)
, _ExecuteGrade(egrade)
, _Target(target)
{
	std::cout	<< "Form constructor"
				<< std::endl;
	if (sgrade < Bureaucrat::_HighestGrade || egrade < Bureaucrat::_HighestGrade)
		throw GradeTooHighException();
	else if (sgrade > Bureaucrat::_LowestGrade || egrade > Bureaucrat::_LowestGrade)
		throw GradeTooLowException();
}

Form::~Form()
{
	std::cout	<< "Form default destructor"
				<< std::endl;
}

Form::Form( const Form& original )
: _Name(original.getName())
, _isSigned(false)
, _SignGrade(original.getSigneGrade())
, _ExecuteGrade(original.getExecuteGrade())
, _Target(original.getTarget())
{
	std::cout	<< "Form copy constructor"
				<< std::endl;
	*this = original;
}

// overload operator
Form&	Form::operator=( const Form& right )
{
	_isSigned = right._isSigned;
	return *this;
}

const std::string&	Form::getName() const
{
	return _Name;
}

bool				Form::getisSigned() const
{
	return _isSigned;
}

int					Form::getSigneGrade() const
{
	return _SignGrade;
}

int					Form::getExecuteGrade() const
{
	return _ExecuteGrade;
}

const std::string&	Form::getTarget() const
{
	return _Target;
}

void				Form::beSigned( const Bureaucrat& b )
{
	if (b.getGrade() > getSigneGrade())
		throw GradeTooLowException();
	_isSigned = true;
}

void				Form::beExcuted( const Bureaucrat& b ) const
{
	if (!getisSigned())
		throw FormNotSigned();
	if (b.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	execute(b);
}

// exeption class method
const char*		Form::GradeTooHighException::what() const _NOEXCEPT
{
	return "Grade Too High";
}

const char*		Form::GradeTooLowException::what() const _NOEXCEPT
{
	return "Grade Too Low";
}


const char*		Form::FormNotSigned::what() const _NOEXCEPT
{
	return "form is not signed";
}

// external function
std::ostream&	operator<<( std::ostream& os, const Form& right )
{
	os	<< "<" << right.getName() << ">"
		<< ", is signed or not "
		<< "<" << right.getisSigned() << ">"
		<< ", sign grade "
		<< "<" << right.getSigneGrade() << ">"
		<< ", execute grade "
		<< "<" << right.getExecuteGrade() << ">"
		<< ", target "
		<< "<" << right.getTarget() << ">"
		<< ".";
	return os;
}
