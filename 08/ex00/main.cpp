#include "easyfind.hpp"
#include <iostream>
#include <list>

int main()
{
    typedef std::list<int> IntList;

    const int table[] = {0, 1, 2, 3, 4};

    IntList lst(table, table + 5);

    std::cout << *easyfind(lst, 3) << std::endl;
}
