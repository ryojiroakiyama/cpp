#include "mutantstack.hpp"
#include <iostream>
#include <stack>
#include <list>

template <typename T>
void OutAll(std::stack<T> s)
{
}

int main()
{
	{
		std::cout << "MutantStack" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::stack<int> s(mstack); return 0;
	}
	{
		std::cout << "stack" << std::endl;
		std::stack<int> oristack;
		oristack.push(5);
		oristack.push(17);
		std::cout << oristack.top() << std::endl;
		oristack.pop();
		std::cout << oristack.size() << std::endl;
		oristack.push(3); oristack.push(5); oristack.push(737); //[...] oristack.push(0);
		//std::stack<int>::iterator it = oristack.begin(); std::stack<int>::iterator ite = oristack.end();
		//++it;
		//--it;
		//while (it != ite) {
		//	std::cout << *it << std::endl;
		//++it; }
		//std::stack<int> s(oristack); return 0;
	}
}
