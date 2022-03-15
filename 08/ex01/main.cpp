#include "span.hpp"
#include <iostream>

int main()
{
	span s(3);
	s.addNumber(1);
	s.addNumber(2);
	s.addNumber(3);
	std::cout << s << std::endl;
}
