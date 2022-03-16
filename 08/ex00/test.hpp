#ifndef TEST_HPP
#define TEST_HPP

#include "escape_sequence.hpp"
#include <iostream>

static void ColorMessage(const std::string color, const std::string message)
{
	std::cout << color << message << RESET << std::endl;
}

template <typename T>
static void Exec(T& container, const int target)
{
	try
	{
		if (*easyfind(container, target) == target) {
			ColorMessage(GREEN, "element found");
		} else {
			ColorMessage(RED, "no element, no exception");
		}
	}
	catch(const NotFound& e)
	{
		ColorMessage(MAGENTA, e.what());
	}
}

template <typename T, typename Iter>
void Test(Iter itBegin, Iter itEnd, const int target)
{
	T container(itBegin, itEnd);
	Exec(container, target);
}

#endif
