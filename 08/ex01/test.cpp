#include "test.hpp"
#include "span.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <iomanip>

void SpanInfo(Span& s)
{
	std::cout		<< "Span  "
					<< "capacity: " << s.getCapacity() << "  "
					<< "content: ";
	if (20 < s.getCapacity())
	{
		std::cout	<< "[ "
					<< *(s.getIterBegin())
					<< " ~ "
					<< *(--s.getIterEnd())
					<< " ]";
	}
	else
	{
		std::cout	<< s;
	}
	std::cout		<< std::endl;
}

void TestAll(Span& s, const int addNum)
{
	TestAddNumber(s, addNum);
	TestShortestSpan(s);
	TestLongestSpan(s);
}

const int w = 15;

void TestAddNumber(Span& s, const int addNum)
{
	std::cout << std::setw(w) << "addNumber: ";
	try
	{
		const bool is_added = s.addNumber(addNum);
		if (is_added)
		{
			std::cout	<< GREEN << std::boolalpha << is_added << RESET
						<< " (" << addNum << " added)" << std::endl;
		}
		else
		{
			std::cout	<< CYAN << std::boolalpha << is_added << RESET
						<< " (" << addNum << " tried)" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr		<< MAGENTA << e.what() << RESET
						<< " (" << addNum << " tried)" << std::endl;
	}
}

void TestShortestSpan(Span& s)
{
	std::cout		<< std::setw(w) << "shortestSpan: ";
	try
	{
		const unsigned int result = s.shortestSpan();
		std::cout	<< GREEN << result << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< MAGENTA << e.what() << RESET << std::endl;
	}
}

void TestLongestSpan(Span& s)
{
	std::cout		<< std::setw(w) << "longestSpan: ";
	try
	{
		const unsigned int result = s.longestSpan();
		std::cout	<< GREEN << result << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< MAGENTA << e.what() << RESET << std::endl;
	}
}
