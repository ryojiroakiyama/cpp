#include "easyfind.hpp"
#include "test.hpp"
#include <iomanip>
#include <ctime>
#include <vector>
#include <list>
#include <deque>
#include <set>

static void PutElement(const int elementSize)
{
    for (int i = 0; i < elementSize; i++)
        std::cout << i << ", ";
    std::cout << std::endl;
}

int main()
{
    std::cout << CLEAR;

    // generate test sources
    std::srand(time(0));
    const int elementRange = 10;
    const int elementSize = std::rand() % elementRange;
    const int targetRange = ((elementSize == 0)? 1 : elementSize * 2);
    const int target = std::rand() % targetRange;

    // print test message
    std::cout   << std::setw(8) << "element:";
    PutElement(elementSize);
    std::cout   << std::setw(8) << "target:" << target << std::endl;

    // test
    std::cout << std::endl;
    {
        std::cout << "vector" << std::endl;
        typedef std::vector<int> IntVector;
        Test<IntVector>(elementSize,target);
    }
    {
        std::cout << "list" << std::endl;
        typedef std::list<int> IntList;
        Test<IntList>(elementSize,target);
    }
    {
        std::cout << "deque" << std::endl;
        typedef std::deque<int> IntDeque;
	    Test<IntDeque>(elementSize,target);
    }
    {
        std::cout << "set" << std::endl;
        typedef std::set<int> IntSet;
	    Test<IntSet>(elementSize,target);
    }
    {
        std::cout << "multiset" << std::endl;
        typedef std::multiset<int> IntMulSet;
	    Test<IntMulSet>(elementSize,target);
    }
}
