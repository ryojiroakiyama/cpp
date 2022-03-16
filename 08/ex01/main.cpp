#include "test.hpp"

int main()
{
	{
		span s(0);
		TestAll(s, 4);
	}
	{
		span s(1);
		s.addNumber(1);
		TestAll(s, 2);
	}
	{
		span s(5);
		s.addNumber(1);
		s.addNumber(2);
		s.addNumber(3);
		s.addNumber(4);
		s.addNumber(5);
		SpanInfo(s);
		TestAddNumber(s, 6);
	}
	{
		const unsigned int cap = 10000;
		span s(cap);
		for (unsigned int i = 0; i < cap; i++)
			s.addNumber(i);
		SpanInfo(s);
		TestAddNumber(s, cap);
		TestShortestSpan(s);
		TestLongestSpan(s);
	}
}
