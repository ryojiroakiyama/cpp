#include "Bureaucrat.hpp"
#include "escape_sequence.hpp"

void	status(Bureaucrat &b)
{
	std::cout	<< MAGENTA
				<< "[status] "
				<< b
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
	testname("higher argument");
	try
	{
		Bureaucrat	Ben("Ben", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("lower argument");
	try
	{
		Bureaucrat	Ben("Ben", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("over high limit");
	try
	{
		Bureaucrat	Ben("Ben", 10);
		for (int grade = 10; grade > 1; grade--)
			Ben.Upgrade();
		status(Ben);
		Ben.Upgrade();
		status(Ben);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("over low limit");
	try
	{
		Bureaucrat	Ben("Ben", 140);
		for (int grade = 140; grade < 150; grade++)
			Ben.Downgrade();
		status(Ben);
		Ben.Downgrade();
		status(Ben);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
