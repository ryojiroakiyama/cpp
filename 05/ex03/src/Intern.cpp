#include "Intern.hpp"

Intern::Intern()
{
	std::cout	<< "Intern constructor"
				<< std::endl;
	CreateFormFunctions[0] = &Intern::CreateNon;
	CreateFormFunctions[1] = &Intern::CreateShrubbery;
	CreateFormFunctions[2] = &Intern::CreateRobotomy;
	CreateFormFunctions[3] = &Intern::CreatePresident;
}

Intern::~Intern()
{
	std::cout	<< "Intern default destructor"
				<< std::endl;
}

Intern::Intern( const Intern& original )
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

Form*	Intern::CreateNon(const std::string& Target)
{
	(void)Target;
	std::cout	<< "The requested form has no match."
				<< std::endl;
	return 0;
}

Form*	Intern::CreateShrubbery(const std::string& Target)
{	
	std::cout	<< "Intern creates ShrubberyCreationForm."
				<< std::endl;
	return new ShrubberyCreationForm(Target);
}

Form*	Intern::CreateRobotomy(const std::string& Target)
{
	std::cout	<< "Intern creates RobotomyRequestForm."
				<< std::endl;
	return new RobotomyRequestForm(Target);
}

Form*	Intern::CreatePresident(const std::string& Target)
{
	std::cout	<< "Intern creates PresidentialPardonForm."
				<< std::endl;
	return new PresidentialPardonForm(Target);
}

// method
Form*	Intern::makeForm(const std::string& FormType, const std::string& Target)
{
	int idx =	(FormType == "shrubbery creation") * 1 +
				(FormType == "robotomy request") * 2 +
				(FormType == "presidential pardon") * 3;
	return (this->*CreateFormFunctions[idx])(Target);
}
