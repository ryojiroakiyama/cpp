#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

const int	RobotomyRequestForm::ToSignGrade = 72;
const int	RobotomyRequestForm::ToExecuteGrade = 45;

RobotomyRequestForm::RobotomyRequestForm( std::string target )
: Form("RobotomyRequestForm", ToSignGrade, ToExecuteGrade, target)
{
	std::cout	<< "RobotomyRequestForm constructor"
				<< std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout	<< "RobotomyRequestForm default destructor"
				<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& original )
: Form(original.getName(), ToSignGrade, ToExecuteGrade, original.getTarget())
{
	std::cout	<< "RobotomyRequestForm copy constructor"
				<< std::endl;
	*this = original;
}

// overload operator
RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& right )
{
	(void)right;
	return *this;
}

// method
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
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
std::ostream&	operator<<( std::ostream& os, const RobotomyRequestForm& right )
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
