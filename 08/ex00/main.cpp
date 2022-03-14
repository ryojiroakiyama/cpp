#include "easyfind.hpp"
#include "test.hpp"
#include <iomanip>
#include <ctime>
#include <list>
#include <vector>
#include <set>
#include <algorithm>

void putInt(int i)
{
    std::cout << i << ", ";
}

int main()
{
    std::cout << CLEAR;

    // make contents
    const int contentSize = 10;
    int content[contentSize];
    for (int i = 0; i < contentSize; i++) {
        content[i] = i;
    }

    // generate test sources
    std::srand(time(0));
    const int maxContentRange = contentSize;
    const int contentRange = std::rand() % (maxContentRange + 1);
    const int maxSearchNum = contentSize * 2;
    const int searchNum = std::rand() % (maxSearchNum + 1);

    // print test message
    std::cout   << std::setw(10) << "content:";
    std::for_each(content, content + contentRange, putInt);
    std::cout   << std::endl;
    std::cout   << std::setw(10) << "searchNum:" << searchNum << std::endl;

    // test
    std::cout << std::endl;
    {
        std::cout << "vector" << std::endl;
        typedef std::vector<int> IntVector;
        IntVector vct(content, content + contentRange);
        test(vct, searchNum);
    }
    {
        std::cout << "list" << std::endl;
        typedef std::list<int> IntList;
        IntList lst(content, content + contentRange);
        test(lst, searchNum);
    }
    {
        std::cout << "set" << std::endl;
        typedef std::set<int> IntSet;
        IntSet set(content, content + contentRange);
	    test(set, searchNum);
    }
}
