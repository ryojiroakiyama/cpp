#include "test.hpp"
#include <iostream>
#include <ctime>

int RandomInt()
{
	static unsigned int seed = time(0);

	std::srand(seed);
	int random_int = std::rand();
	seed = random_int;
	return random_int;
}

int main()
{
	{
		std::cout << std::endl;
		span s(0);
		SpanInfo(s);
		TestAll(s, 0);
	}
	{
		std::cout << std::endl;
		span s(1);
		s.addNumber(1);
		SpanInfo(s);
		TestAll(s, 2);
	}
	{
		std::cout << std::endl;
		span s(2);
		s.addNumber(1);
		SpanInfo(s);
		TestAddNumber(s, 1);
		TestAll(s, 2);
	}
	{
		std::cout << std::endl;
		const unsigned int	cap = 10;
		const int			addNumRange = 1000;
		span s(cap);
		SpanInfo(s);
		for (unsigned int i = 0; i < cap; i++)
			TestAddNumber(s, RandomInt() % addNumRange);
		SpanInfo(s);
		TestAll(s, 5);
	}
	{
		std::cout << std::endl;
		const unsigned int cap = 100000;
		span s(cap);
		for (unsigned int i = 0; i < cap; i++)
			s.addNumber(i);
		SpanInfo(s);
		TestAll(s, cap);
	}
}
