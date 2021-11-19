#include "Bureaucrat.hpp"

const int	Bureaucrat::_HighestGrade = 1;
const int	Bureaucrat::_LowestGrade = 150;

// constructor, destructor
Bureaucrat::Bureaucrat() : _Name("B"), _Grade(150)
{
	std::cout	<< "Bureaucrat default constructor"
				<< std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _Name(name), _Grade(grade)
{
	std::cout	<< "Bureaucrat constructor"
				<< std::endl;
	if (grade < _HighestGrade)
		throw GradeTooHighException();
	else if (grade > _LowestGrade)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout	<< "Bureaucrat default destructor"
				<< std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& original )
{
	std::cout	<< "Bureaucrat copy constructor"
				<< std::endl;
	*this = original;
}

// overload operator
Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& right )
{
	_Grade = right._Grade;
	return *this;
}

std::string const&	Bureaucrat::getName() const
{
	return _Name;
}

int					Bureaucrat::getGrade() const
{
	return _Grade;
}

void				Bureaucrat::Upgrade()
{
	_Grade--;
	if (_Grade < _HighestGrade)
		throw GradeTooHighException();
}

void				Bureaucrat::Downgrade()
{
	_Grade++;
	if (_Grade > _LowestGrade)
		throw GradeTooLowException();
}

// exeption class method
const char*		Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return "Grade Too High";
}

const char*		Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return "Grade Too Low";
}

// external function
std::ostream&	operator<<( std::ostream& os, const Bureaucrat& right )
{
	os	<< "<" << right.getName() << ">"
		<< ", bureaucrat grade "
		<< "<" << right.getGrade() << ">.";
	return os;
}
