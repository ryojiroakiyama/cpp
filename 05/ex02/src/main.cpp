#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "escape_sequence.hpp"

void	bstatus(Bureaucrat &b)
{
	std::cout	<< MAGENTA
				<< "[status] "
				<< b
				<< RESET
				<< std::endl;
}

void	fstatus(Form &f)
{
	std::cout	<< MAGENTA
				<< "[status] "
				<< f
				<< RESET
				<< std::endl;
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
		Bureaucrat b("Ben", 100);
		ShrubberyCreationForm s("home");
		b.signForm(s);
		b.executeForm(s);
		bstatus(b);
		fstatus(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("RobotomyRequestForm");
	try
	{
		Bureaucrat b("Ben", 35);
		RobotomyRequestForm s("home");
		b.signForm(s);
		b.executeForm(s);
		bstatus(b);
		fstatus(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
