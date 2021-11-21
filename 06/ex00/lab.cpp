#include <iostream>
#include <sstream>
#include <iomanip>
#include <float.h>

int main(int argc, char *argv[])
{
	std::cout	<< std::numeric_limits<float>::max() << std::endl;
	std::cout	<< std::numeric_limits<float>::min() << std::endl;
	std::cout	<< std::setprecision(1000) << std::numeric_limits<float>::max() << std::endl;
	std::cout	<< std::setprecision(1000) << std::numeric_limits<float>::min() << std::endl;
	std::cout	<< std::setprecision(1000) << std::numeric_limits<double>::max() << std::endl;
	std::cout	<< std::setprecision(1000) << std::numeric_limits<double>::min() << std::endl;
	try
	{
		if (argc != 2)
			throw "invalid arguments number";
		std::string	src(argv[1]);
		try
		{
			std::cout	<< "c:"
						<< static_cast<char>(std::stoi(src))
						<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout	<< "impossible" << std::endl;
			std::cerr	<< e.what() << std::endl;
		}
		try
		{
			std::cout	<< "int:"
						<< std::stoi(src)
						<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout	<< "impossible" << std::endl;
			std::cerr	<< e.what() << std::endl;
		}
		try
		{
			std::cout	<< "float:"
						<< std::stof(src)
						<< std::endl;
			std::cout	<< std::setprecision(15) << std::stof(src) << std::endl;
			std::cout	<< std::setprecision(15) << static_cast<int>(std::stof(src)) << std::endl;
			std::cout	<< std::setprecision(15) << static_cast<double>(std::stof(src)) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout 	<< "impossible" << std::endl;
			std::cerr 	<< e.what() << std::endl;
		}
		try
		{
			std::cout	<< "double:"
						<< std::stod(src)
						<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout 	<< "impossible" << std::endl;
			std::cerr 	<< e.what() << std::endl;
		}
	}
	catch(const char *message)
	{
		std::cerr	<< message
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
