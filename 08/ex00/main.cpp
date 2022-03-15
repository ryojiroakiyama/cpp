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
    std::cout   << std::setw(10) << "content:";
    PutContent(size_content);
    std::cout   << std::setw(10) << "target:" << target << std::endl;

    // test
    std::cout << std::endl;

    std::cout << "vector" << std::endl;
    Test<std::vector<int> >(size_content,target);

    std::cout << "list" << std::endl;
    Test<std::list<int> >(size_content,target);

    std::cout << "deque" << std::endl;
    Test<std::deque<int> >(size_content,target);

    std::cout << "set" << std::endl;
    Test<std::set<int> >(size_content,target);

    std::cout << "multiset" << std::endl;
    Test<std::multiset<int> >(size_content,target);
}
