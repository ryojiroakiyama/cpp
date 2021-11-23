#include <iostream>
#include "iter.hpp"

int main( void )
{
	const int length = 5;
	int	array[length] = {0, 1, 2, 3, 4};
	iter<int, void>(array, length, put_element);
	std::cout << "^^^^^^^^^before twice" << std::endl;
	iter<int, std::string>(array, length, twice);
	iter<int, void>(array, length, put_element);
	std::cout << "^^^^^^^^^after twice" << std::endl;

	iter<const char, void>("hello", 5, put_element);
	std::cout << "^^^^^^^^^" << std::endl;

	std::string str[length] = {"abc", "def", "ghi", "jkl", "mno"};
	iter<std::string, void>(str, length, put_element);
}
