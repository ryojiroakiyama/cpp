#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(const T array[], const size_t length, void (*function)(T))
{
	for (size_t idx = 0; idx < length; idx++)
		function(array[idx]);
}

template <typename T>
void	put_element(T element)
{
	std::cout << element << std::endl;
}

#endif
