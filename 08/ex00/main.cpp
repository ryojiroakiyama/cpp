#include "easyfind.hpp"
#include "escape_sequence.hpp"
#include <iostream>
#include <list>
#include <vector>

void	ColorMessage(const std::string color, const std::string message)
{
	std::cout << color << message << RESET << std::endl;
}

template <typename T>
void	test(const T& container, const int target)
{
    if (*easyfind(container, target) == target)
        ColorMessage(GREEN, "ok");
	else
		ColorMessage(RED, "no");
}

int main()
{
    typedef std::vector<int> IntVector;
    typedef std::list<int> IntList;

    const int table[] = {0, 1, 2, 3, 4};

    IntVector vct(table, table + 5);
    IntList lst(table, table + 5);

	test(vct, 4);
	test(lst, 3);
}
