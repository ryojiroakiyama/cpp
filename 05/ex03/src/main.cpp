#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "escape_sequence.hpp"

void	test(Bureaucrat &B, Form *F)
{
	std::cout	<< GREEN;
	B.signForm(*F);
	B.executeForm(*F);
	std::cout	<< MAGENTA
				<< "[Bureaucrat] " << B << std::endl
				<< "[Form]" << *F << std::endl
				<< RESET;
}

void	testname(std::string s)
{
	std::cout	<< CYAN
				<< s
				<< RESET
				<< std::endl;
}

int main( void )
{
	Intern	someRandomIntern;
	Form	*createdForm;
	testname("ShrubberyCreationForm");
	try
	{
		Bureaucrat B("Ben", 100);
		std::cout	<< YELLOW;
		createdForm = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout	<< RESET;
		test(B, createdForm);
		delete(createdForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("RobotomyRequestForm");
	try
	{
		Bureaucrat B("Ben", 35);
		std::cout	<< YELLOW;
		createdForm = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout	<< RESET;
		test(B, createdForm);
		delete(createdForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("PresidentialPardonForm");
	try
	{
		Bureaucrat B("Ben", 5);
		std::cout	<< YELLOW;
		createdForm = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout	<< RESET;
		test(B, createdForm);
		delete(createdForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("no match form");
	try
	{
		Bureaucrat B("Ben", 5);
		std::cout	<< YELLOW;
		createdForm = someRandomIntern.makeForm("a", "Bender");
		std::cout	<< RESET;
		if (createdForm)
		{
			test(B, createdForm);
			delete(createdForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("empty target");
	try
	{
		Bureaucrat B("Ben", 5);
		std::cout	<< YELLOW;
		createdForm = someRandomIntern.makeForm("presidential pardon", "");
		std::cout	<< RESET;
		if (createdForm)
		{
			test(B, createdForm);
			delete(createdForm);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
