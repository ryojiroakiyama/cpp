#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern( const Intern& original );
		Intern&	operator=( const Intern& right );
		Form*	makeForm(const std::string&, const std::string&);
	private:
		Form*	(Intern::*CreateFormFunctions[4])(const std::string&);
		Form*	CreateNon(const std::string&);
		Form*	CreateShrubbery(const std::string&);
		Form*	CreateRobotomy(const std::string&);
		Form*	CreatePresident(const std::string&);
};

#endif
