#include "easyfind.hpp"
#include "test.hpp"
#include <iomanip>
#include <ctime>
#include <list>
#include <vector>
#include <set>

int main()
{
    std::cout << CLEAR;

    // make contents
    const int contentSize = 10;
    int content[contentSize];
    for (int i = 0; i < contentSize; i++) {
        content[i] = i;
    }

    // generate test num
    std::srand(time(0));
    int randRange = contentSize * 2;
    int target = std::rand() % (randRange);

    // print test message
    std::cout   << std::setw(8) << "content:" << "0 ~ " << contentSize << std::endl
                << std::setw(8) << "target:" << target << std::endl;

    std::cout << std::endl;
    {
        std::cout << "vector" << std::endl;
        typedef std::vector<int> IntVector;
        IntVector vct(content, content + contentSize);
	    test(vct, target);
    }
    {
        std::cout << "list" << std::endl;
        typedef std::list<int> IntList;
        IntList lst(content, content + contentSize);
	    test(lst, target);
    }
    {
        std::cout << "set" << std::endl;
        typedef std::set<int> IntSet;
        IntSet set(content, content + contentSize);
	    test(set, target);
    }
}
