#include "Intern.hpp"

const int	Intern::ToSignGrade = 25;
const int	Intern::ToExecuteGrade = 5;

Intern::Intern( std::string target )
: Form("Intern", ToSignGrade, ToExecuteGrade, target)
{
	std::cout	<< "Intern constructor"
				<< std::endl;
}

Intern::~Intern()
{
	std::cout	<< "Intern default destructor"
				<< std::endl;
}

Intern::Intern( const Intern& original )
: Form(original.getName(), ToSignGrade, ToExecuteGrade, original.getTarget())
{
	std::cout	<< "Intern copy constructor"
				<< std::endl;
	*this = original;
}

// overload operator
Intern&	Intern::operator=( const Intern& right )
{
	(void)right;
	return *this;
}

// method
void	Intern::action() const
{
	std::cout	<< "<" << getTarget() << ">"
				<< " has been pardoned by Zafod Beeblebrox."
				<< std::endl;
}

// external function
std::ostream&	operator<<( std::ostream& os, const Intern& right )
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
