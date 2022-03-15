#include "test.hpp"
#include "span.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <iomanip>

const int w = 20;

static void TestaddNumber(span& s, const unsigned int addNum)
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

static void TestshortestSpan(span& s)
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

static void TestlongestSpan(span& s)
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

void ErrorTest()
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
