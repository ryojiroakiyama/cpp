#include <iostream>
#include <sstream>

enum e_type
{
	CHAR,//0
	INT,//1
	FLOAT,//2
	FLOAT_PSEUDO,//3
	DOUBLE,//4
	DOUBLE_PSEUDO,//5
	TYPE_NUM//6
};

e_type	get_type(std::string src)
{
	if (src == "-inff" || src == "+inff" || src == "nanf")
		return FLOAT_PSEUDO;
	else if (src == "-inf" || src == "+inf" || src == "nan")
		return DOUBLE_PSEUDO;
	else if (src.size() == 1 && 'a' <= src.at(0) && src.at(0))
		return CHAR;
	else if (src.at(src.size() - 1) == 'f')
		return FLOAT;
	else if (src.find('.') != std::string::npos)
		return DOUBLE;
	else
		return INT;
}

int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw "invalid arguments number";
		std::string	src(argv[1]);
		std::cout << get_type(src) << std::endl;
		//try
		//{
		//	std::cout	<< "c:"
		//				<< static_cast<char>(std::stoi(src))
		//				<< std::endl;
		//}
		//catch(const std::exception& e)
		//{
		//	std::cout	<< "impossible" << std::endl;
		//	std::cerr	<< e.what() << std::endl;
		//}
		//try
		//{
		//	std::cout	<< "int:"
		//				<< std::stoi(src)
		//				<< std::endl;
		//}
		//catch(const std::exception& e)
		//{
		//	std::cout	<< "impossible" << std::endl;
		//	std::cerr	<< e.what() << std::endl;
		//}
		//try
		//{
		//	std::cout	<< "float:"
		//				<< std::stof(src)
		//				<< std::endl;
		//}
		//catch(const std::exception& e)
		//{
		//	std::cout 	<< "impossible" << std::endl;
		//	std::cerr 	<< e.what() << std::endl;
		//}
		//try
		//{
		//	std::cout	<< "double:"
		//				<< std::stod(src)
		//				<< std::endl;
		//}
		//catch(const std::exception& e)
		//{
		//	std::cout 	<< "impossible" << std::endl;
		//	std::cerr 	<< e.what() << std::endl;
		//}
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
