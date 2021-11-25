#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

const int	PresidentialPardonForm::ToSignGrade = 25;
const int	PresidentialPardonForm::ToExecuteGrade = 5;

PresidentialPardonForm::PresidentialPardonForm( std::string target )
: Form("PresidentialPardonForm", ToSignGrade, ToExecuteGrade, target)
{
	std::cout	<< "PresidentialPardonForm constructor"
				<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout	<< "PresidentialPardonForm default destructor"
				<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& original )
: Form(original.getName(), ToSignGrade, ToExecuteGrade, original.getTarget())
{
	std::cout	<< "PresidentialPardonForm copy constructor"
				<< std::endl;
	*this = original;
}

// overload operator
PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& right )
{
	(void)right;
	return *this;
}

// method
void	PresidentialPardonForm::action() const
{
	std::cout	<< "wheeeeeeeee"
				<< std::endl;
	std::srand( time(0) );
	if (std::rand() % 2 == 0)
	{
		std::cout	<< "<" << getTarget() << ">"
					<< " has been robotomized successfully."
					<< std::endl;
	}
	else
	{
		std::cout	<< "<" << getTarget() << ">"
			<< " Failed to robotomize."
			<< std::endl;
	}
}

// external function
std::ostream&	operator<<( std::ostream& os, const PresidentialPardonForm& right )
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
