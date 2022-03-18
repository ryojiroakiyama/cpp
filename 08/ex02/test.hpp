#include "mutantstack.hpp"

template <typename T>
void OutAll(std::stack<T> s)
{
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
}

template <typename T>
void Test()
{
	/* template test */
}
