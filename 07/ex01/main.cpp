#include <iostream>
#include "iter.hpp"

int main( void )
{
	const int length = 5;
	int	array[length] = {0, 1, 2, 3, 4};
	iter(array, length, put_element);

	iter("hello", 5, put_element);

	std::string str[length] = {"abc", "def", "ghi", "jkl", "mno"};
	iter(str, length, put_element);
}
