#include "mutantstack.hpp"
#include "escape_sequence.hpp"
#include "test.hpp"
#include <iostream>
#include <stack>
#include <list>

int main()
{
/*
	{
		std::cout << std::endl;
		std::cout << GREEN << "provided test" << RESET << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::stack<int> s(mstack);
	}
*/

	/* Additional Test */
	{
		std::cout << std::endl;
		std::cout << GREEN << "Stack" << RESET << std::endl;
		std::stack<int> oristack;
		COMMONTEST(oristack);
		OutAll(oristack);

		std::cout << std::endl;
		std::cout << GREEN << "MutantStack" << RESET << std::endl;
		MutantStack<int> mstack;
		COMMONTEST(mstack);
		IteratorTest(mstack);
		ReverseIteratorTest(mstack);
		OutAll(mstack);

		std::cout << std::endl;
		std::cout << GREEN << "Stack(MutantStack)" << RESET << std::endl;
		std::stack<int> copystack(mstack);
		OutAll(copystack);

		std::cout << std::endl;
		std::cout << GREEN << "const MutantStack(MutantStack)" << RESET << std::endl;
		const MutantStack<int> ccmstack(mstack);
		IteratorTest(ccmstack);
		ReverseIteratorTest(ccmstack);
	}
}
