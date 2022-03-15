#include "span.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <iomanip>

const int w = 20;

void TestaddNumber(span& s, const unsigned int addNum)
{
	std::cout << std::setw(w) << "Test addNumber: ";
	try
	{
		s.addNumber(addNum);
		std::cout << RED << "no exception thrown" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << MAGENTA << e.what() << RESET << '\n';
	}
}

void TestshortestSpan(span& s)
{
	std::cout << std::setw(w) << "Test shortestSpan: ";
	try
	{
		s.shortestSpan();
		std::cout << RED << "no exception thrown" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << MAGENTA << e.what() << RESET << '\n';
	}
}

void TestlongestSpan(span& s)
{
	std::cout << std::setw(w) << "Test longestSpan: ";
	try
	{
		s.longestSpan();
		std::cout << RED << "no exception thrown" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << MAGENTA << e.what() << RESET << '\n';
	}
}

void SpanInfo(span& s)
{
	std::cout	<< "span"
				<< "  "
				<< "capacity: " << s.getCapacity()
				<< "  "
				<< "content: "  << s
				<< std::endl;
}

int main()
{
	{
		{
			span s(0);
			SpanInfo(s);
			TestaddNumber(s, 4);
			TestshortestSpan(s);
			TestlongestSpan(s);
		}
		{
			span s(1);
			s.addNumber(1);
			SpanInfo(s);
			TestaddNumber(s, 2);
			TestshortestSpan(s);
			TestlongestSpan(s);
		}
		{
			span s(5);
			s.addNumber(1);
			s.addNumber(2);
			s.addNumber(3);
			s.addNumber(4);
			s.addNumber(5);
			SpanInfo(s);
			TestaddNumber(s, 6);
		}
	}
	//span s(10);
	//try
	//{
	//	s.addNumber(1);
	//	std::cout << std::boolalpha << s.addNumber(1) << std::endl;
	//	s.addNumber(55);
	//	s.addNumber(99);
	//	s.addNumber(1000);
	//}
	//catch(const span::OutRange& e)
	//{
	//	std::cerr << e.what() << std::endl;
	//}
	//std::cout << s << std::endl;
	//std::cout << s.shortestSpan() << std::endl;
	//std::cout << s.longestSpan() << std::endl;
}
