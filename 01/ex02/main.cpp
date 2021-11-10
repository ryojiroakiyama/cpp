#include <iostream>
#include <iomanip>
#include "escape_sequence.hpp"

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		*stringPTR = &str;
	std::string&	stringREF = str;

	std::cout	<< "address" << std::endl
				<< MAGENTA
				<< std::setw(10) << "str:" << &str << std::endl
				<< std::setw(10) << "stringPTR:" << stringPTR << std::endl
				<< std::setw(10) << "stringREF:" << &stringREF << std::endl
				<< RESET
				<< "string" << std::endl
				<< CYAN
				<< std::setw(10) << "stringPTR:" << *stringPTR << std::endl
				<< std::setw(10) << "stringREF:" << stringREF << std::endl
				<< RESET;
}
