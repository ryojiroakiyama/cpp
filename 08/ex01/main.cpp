#include "test.hpp"

int main()
{
	{
		span s(0);
		SpanInfo(s);
		TestAll(s, 0);
	}
	{
		span s(1);
		s.addNumber(1);
		SpanInfo(s);
		TestAll(s, 2);
	}
	{
		span s(2);
		s.addNumber(1);
		SpanInfo(s);
		TestAddNumber(s, 1);
		TestAll(s, 2);
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
