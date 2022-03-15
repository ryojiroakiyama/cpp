#include "easyfind.hpp"
#include "test.hpp"
#include <iomanip>
#include <ctime>
#include <vector>
#include <list>
#include <deque>
#include <set>

static void PutContent(const int size_content)
{
    for (int i = 0; i < size_content; i++)
        std::cout << i << ", ";
    std::cout << std::endl;
}

int main()
{
    std::cout << CLEAR;

    // generate test sources
    std::srand(time(0));
    const int range_content = 10;
    const int size_content = std::rand() % range_content;
    const int range_target = ((size_content == 0)? 1 : size_content * 2);
    const int target = std::rand() % range_target;

    // print test message
    std::cout   << std::setw(8) << "elem:";
    PutContent(size_content);
    std::cout   << std::setw(8) << "target:" << target << std::endl;

    // test
    std::cout << std::endl;
    {
        std::cout << "vector" << std::endl;
        typedef std::vector<int> IntVector;
        Test<IntVector>(size_content,target);
    }
    {
        std::cout << "list" << std::endl;
        typedef std::list<int> IntList;
        Test<IntList>(size_content,target);
    }
    {
        std::cout << "deque" << std::endl;
        typedef std::deque<int> IntDeque;
	    Test<IntDeque>(size_content,target);
    }
    {
        std::cout << "set" << std::endl;
        typedef std::set<int> IntSet;
	    Test<IntSet>(size_content,target);
    }
    {
        std::cout << "multiset" << std::endl;
        typedef std::multiset<int> IntMulSet;
	    Test<IntMulSet>(size_content,target);
    }
}
