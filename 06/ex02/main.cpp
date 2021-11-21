#include <iostream>
#include <ctime>
#include <cstdlib>
#include "main.hpp"

Base*	generate(void)
{
	std::srand(time(0));
	int result = std::rand() % 3;
	std::cout		<< "generate";
	if (result == 0)
	{
		std::cout	<<  "A" << std::endl;
		return new A();
	}
	else if (result == 1)
	{
		std::cout	<< "B" << std::endl;
		return new B();
	}
	else
	{
		std::cout	<< "C" << std::endl;
		return new C();
	}
}

void	identify(Base* p)
{
	std::cout		<< "idendify(*)";
	if (dynamic_cast<A*>(p))
	{
		std::cout	<< "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout	<< "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout	<< "C" << std::endl;
	}
}

void	identify(Base& p)
{
	std::cout		<< "identify(&)";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout	<< "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout	<< "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout	<< "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int main(void)
{
	Base*	test;
	test = generate();
	identify(test);
	identify(*test);
}
