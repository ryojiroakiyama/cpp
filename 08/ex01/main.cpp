#include "span.hpp"
#include <iostream>

int main()
{
	span s(3);
	try
	{
		s.addNumber(1);
		s.addNumber(2);
		std::cout << std::boolalpha << s.addNumber(2) << std::endl;
		s.addNumber(3);
		s.addNumber(1000);
	}
	catch(const span::OutRange& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << s << std::endl;
	std::cout << s.shortestSpan() << std::endl;
	std::cout << s.longestSpan() << std::endl;
}
