#include <iostream>
#include "main.hpp"

uintptr_t	serialize(s_data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

s_data*		deserialize(uintptr_t raw)
{
	return reinterpret_cast<s_data*>(raw);
}

int main(void)
{
	s_data		test;
	s_data*		before_ptr = &test;
	s_data*		after_ptr = deserialize(serialize(before_ptr));
	std::cout	<< before_ptr << std::endl
				<< after_ptr << std::endl;
}
