#include "mutantstack.hpp"
#include <iostream>
#include <iomanip>

static void Title(std::string message)
{
	std::cout << "----" << message << "----" << std::endl;
}

template <typename T>
void OutAll(std::stack<T> s)
{
	Title("OutAll");
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	Title("OutAll");
}

const int w = 6;

template <typename T, typename U>
void Push(T& s, U content)
{
	std::cout << std::setw(w) << "push: " << content << std::endl;
	s.push(content);
}

template <typename T>
void Pop(T& s)
{
	std::cout << std::setw(w) << "pop  " << std::endl;
	s.pop();
}

template <typename T>
void Top(T& s)
{
	std::cout << std::setw(w) << "top: " << s.top() << std::endl;
}

template <typename T>
void Size(T& s)
{
	std::cout << std::setw(w) << "size: " << s.size() << std::endl;
}

template <typename T>
void COMMONTEST(T& s)
{
	Title("COMMONTEST");
	Push(s, 1);
	Push(s, 2);
	Top(s);
	Pop(s);
	Size(s);
	Push(s, 2);
	Push(s, 3);
	Push(s, 4);
	Title("COMMONTEST");
}

template <typename T>
void IteratorTest(T& s)
{
	Title("IteratorTest");
	typename T::iterator it = s.begin();
	typename T::iterator ite = s.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	Title("IteratorTest");
}

template <typename T>
void ReverseIteratorTest(T& s)
{
	Title("ReverseIteratorTest");
	typename T::reverse_iterator it = s.rbegin();
	typename T::reverse_iterator ite = s.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	Title("ReverseIteratorTest");
}
