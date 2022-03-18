#include "mutantstack.hpp"
#include "escape_sequence.hpp"
#include "test.hpp"
#include <iostream>
#include <stack>
#include <list>

static void ColorMessage(const std::string color, const std::string message)
{
	std::cout << color << message << RESET << std::endl;
}

int main()
{
	/* provided test */
	//{
	//	MutantStack<int> mstack;
	//	mstack.push(5);
	//	mstack.push(17);
	//	std::cout << mstack.top() << std::endl;
	//	mstack.pop();
	//	std::cout << mstack.size() << std::endl;
	//	mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
	//	MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
	//	++it;
	//	--it;
	//	while (it != ite) {
	//		std::cout << *it << std::endl;
	//	++it; }
	//	std::stack<int> s(mstack);
	//}

	/* Additional Test */
	{
		/* Stack */
		std::cout << std::endl;
		ColorMessage(GREEN, "Stack");
		std::stack<int> oristack;
		COMMONTEST(oristack);
		OutAll(oristack);

		/* MutantStack */
		std::cout << std::endl;
		ColorMessage(GREEN, "MutantStack");
		MutantStack<int> mstack;
		COMMONTEST(mstack);
		IteratorTest(mstack);
		ReverseIteratorTest(mstack);
		OutAll(mstack);

		/* copy Stack */
		std::cout << std::endl;
		ColorMessage(GREEN, "CopyStack");
		std::stack<int> copystack(mstack);
		OutAll(copystack);

		{
			/* copy & const MutantStack */
			std::cout << std::endl;
			ColorMessage(GREEN, "CopyConstMutantStack");
			MutantStack<int> mstack;
			mstack.push(1);
			mstack.push(2);
			mstack.push(3);
			const MutantStack<int> ccmstack(mstack);
			IteratorTest(ccmstack);
			ReverseIteratorTest(ccmstack);
		}
	}
}
