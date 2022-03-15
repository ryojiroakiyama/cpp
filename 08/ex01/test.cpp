#include "test.hpp"
#include "span.hpp"
#include <iostream>

void SpanInfo(span& s)
{
	std::cout	<< "span"
				<< "  "
				<< "capacity: " << s.getCapacity()
				<< "  "
				<< "content: "  << s
				<< std::endl;
}

void TestNormal()
{
	const unsigned int cap = 10000;
	span s(cap);
	for (unsigned int i = 0; i < cap; i++)
		s.addNumber(i);
	std::cout << s.shortestSpan() << std::endl;
	std::cout << s.longestSpan() << std::endl;
	ExceptionAddNumber(s, cap);
}
