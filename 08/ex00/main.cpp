#include "easyfind.hpp"
#include "test.hpp"
#include <iomanip>
#include <ctime>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>

static void PutInt(const int i)
{
    std::cout << i << ", ";
}

int RandomInt()
{
	static unsigned int seed = time(0);

	std::srand(seed);
	int random_int = std::rand();
	seed = random_int;
	return random_int;
}

int main()
{
    std::cout << CLEAR;

    // generate test resources
    // contents: contents of container be tested
    // capacity: size of contents
    // target:   int num to search
    const int range_capacity = 10;
    const int capacity = RandomInt() % range_capacity;
    int *contents = new int[capacity];
    for (int i = 0; i < capacity; i++)
        contents[i] = i;
    const int appearance_rate = 2;
    const int range_target = ((capacity == 0)? 1 : capacity * appearance_rate);
    const int target = RandomInt() % range_target;

    // print test resources
    std::cout   << std::setw(10) << "contents:";
    std::for_each(contents, contents + capacity, PutInt);
    std::cout   << std::endl;
    std::cout   << std::setw(10) << "target:" << target << std::endl;

    // test
    std::cout << std::endl;
    {
        std::cout << "vector" << std::endl;
        typedef std::vector<int> VectInt;
        Test<VectInt>(contents, contents + capacity,target);
        Test<const VectInt>(contents, contents + capacity, target);
    }
    {
        std::cout << "list" << std::endl;
        typedef std::list<int> ListInt;
        Test<ListInt>(contents, contents + capacity, target);
        Test<const ListInt>(contents, contents + capacity, target);
    }
    {
        std::cout << "deque" << std::endl;
        typedef std::deque<int> DeqInt;
        Test<DeqInt>(contents, contents + capacity, target);
        Test<const DeqInt>(contents, contents + capacity, target);
    }
    {
        std::cout << "set" << std::endl;
        typedef std::set<int> SetInt;
        Test<SetInt>(contents, contents + capacity, target);
        Test<const SetInt>(contents, contents + capacity, target);
    }
    {
        std::cout << "multiset" << std::endl;
         typedef std::multiset<int> MulSetInt;
        Test<MulSetInt>(contents, contents + capacity, target);
        Test<const MulSetInt>(contents, contents + capacity, target);
    }
    delete [] contents;
}
