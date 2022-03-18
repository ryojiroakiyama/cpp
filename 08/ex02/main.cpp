#include "mutantstack.hpp"
#include "test.hpp"
#include <iostream>
#include <stack>
#include <list>

int main()
{
		/* MutantStack */
		std::cout << "MutantStack" << std::endl;
		MutantStack<int> mstack;
		mstack.push(1);
		mstack.push(2);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(2);
		mstack.push(3);
		mstack.push(4); //[...] mstack.push(0);
		std::cout << "-------" << std::endl;
		MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }

		/* copy stack */
		std::cout << std::endl;
		std::cout << "copy stack" << std::endl;
		std::stack<int> copystack(mstack);
		OutAll(copystack);

		/* stack */
		std::cout << std::endl;
		std::cout << "stack" << std::endl;
		std::stack<int> oristack;
		oristack.push(1);
		oristack.push(2);
		std::cout << oristack.top() << std::endl;
		oristack.pop();
		std::cout << oristack.size() << std::endl;
		oristack.push(2);
		oristack.push(3);
		oristack.push(4);
		std::cout << "-------" << std::endl;
		OutAll(oristack);
		//std::stack<int>::iterator it = oristack.begin(); std::stack<int>::iterator ite = oristack.end();
		//++it;
		//--it;
		//while (it != ite) {
		//	std::cout << *it << std::endl;
		//++it; }
		//std::stack<int> s(oristack); return 0;
}
