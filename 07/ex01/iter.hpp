#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename U>
void	iter(T array[], const size_t length, U (*function)(T&))
{
	for (size_t idx = 0; idx < length; idx++)
		function(array[idx]);
}

template <typename T>
void		put_element(T element)
{
	std::cout << element << std::endl;
}

template <typename T>
std::string	twice(T& element)
{
	element *= 2;
	return "twiceeeeee";
}

#endif
