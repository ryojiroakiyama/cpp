#include "Bureaucrat.hpp"
#include "Form.hpp"
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
	testname("copy constructor");
	try
	{
		Form f1("Form1", 42, 55);
		fstatus(f1);
		Form f2(f1);
		fstatus(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("higher sign grade");
	try
	{
		Form f("form", 0, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("lower execute grade");
	try
	{
		Form f("form", 100, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("sign");
	try
	{
		Bureaucrat	b("Ben", 100);
		Form		f("Form1", 100);
		std::cout	<< YELLOW;
		b.signForm(f);
		std::cout	<< RESET;
		bstatus(b);
		fstatus(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	testname("cannot sign");
	try
	{
		Bureaucrat	b("Ben", 100);
		Form		f("Form1", 99);
		std::cout	<< YELLOW;
		b.signForm(f);
		std::cout	<< RESET;
		bstatus(b);
		fstatus(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
