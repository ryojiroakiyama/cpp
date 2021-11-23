#include <iostream>
#include "Array.hpp"
#include "escape_sequence.hpp"

template <typename T>
void	access(T& A, unsigned int idx)
{
	std::cout	<< GREEN
				<< "access[" << idx << "] : "
				<< RESET
				<< A[idx]
				<< std::endl;
}

template <typename T>
void	test(std::string s, unsigned int size)
{
	try
	{
		std::cout << CYAN << "[" << s << "]" << RESET<< std::endl;
		Array<T> A(size);
		std::cout	<< GREEN << "size : " << RESET << A.size() << std::endl;
		access(A, 0);
		access(A, size / 2);
		access(A, size - 1);
		access(A, size);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template <typename T>
void	const_test(std::string s, unsigned int size)
{
	try
	{
		std::cout << CYAN << "const test[" << s << "]" << RESET<< std::endl;
		const Array<T> A(size);
		std::cout	<< GREEN << "size : " << RESET << A.size() << std::endl;
		access(A, 0);
		access(A, size / 2);
		access(A, size - 1);
		access(A, size);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
	test<int>("empyt", 0);
	test<int>("int", 10);
	test<char>("char", 100);
	test<std::string>("string", 1);
	test<float>("float", 200);
	test<double>("double", 42);
	test<void*>("void*", 500);
	test<unsigned int*>("unsingned int*", 2);
	const_test<int>("int", 5);
	/*
	** test<char*> -> segv.
	** std::cout access null pointer's contents
	** that same behavior as below.
	** code:
	** char** a = new char*[5]();
	** std::cout << a << std::endl;
	** delete [] a;
	*/
}
