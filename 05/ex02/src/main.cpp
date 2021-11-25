#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
	testname("ShrubberyCreationForm");
	try
	{
		Bureaucrat B("Ben", 100);
		ShrubberyCreationForm S("home");
		test(B, &S);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("RobotomyRequestForm");
	try
	{
		Bureaucrat B("Ben", 35);
		RobotomyRequestForm R("home");
		test(B, &R);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("PresidentialPardonForm");
	try
	{
		Bureaucrat B("Ben", 5);
		PresidentialPardonForm P("home");
		test(B, &P);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
