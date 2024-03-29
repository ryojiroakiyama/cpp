#include "Bureaucrat.hpp"

const int	Bureaucrat::_HighestGrade = 1;
const int	Bureaucrat::_LowestGrade = 150;

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
: _Name(original.getName())
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

void				Bureaucrat::signForm( Form & f )
{
	try
	{
		f.beSigned(*this);
		std::cout	<< "<" << getName() << ">"
					<< " signs "
					<< "<" << f.getName() << ">"
					<< "."
					<< std::endl;
	}
	catch( const std::exception& e )
	{
		std::cout	<< "<" << getName() << ">"
					<< " cannot sign "
					<< "<" << f.getName() << ">"
					<< " because "
					<< "<" << e.what() << ">"
					<< "."
					<< std::endl;
	}
}

void				Bureaucrat::executeForm(Form const& form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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
