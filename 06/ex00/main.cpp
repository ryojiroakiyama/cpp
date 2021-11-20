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

e_type	get_type(double& num, const std::string& src)
{
	if (src == "-inff" || src == "+inff" || src == "nanf")
	{
		num = std::stof(src);
		return FLOAT_PSEUDO;
	}
	else if (src == "-inf" || src == "+inf" || src == "nan")
	{
		num = std::stod(src);
		return DOUBLE_PSEUDO;
	}
	else if (src.size() == 1 && isprint(src.at(0) && !isnumber(src.at(0))))
	{
		num = src.at(0);
		return CHAR;
	}
	else if (src.at(src.size() - 1) == 'f')
	{
		num = std::stof(src);
		return FLOAT;
	}
	else if (src.find('.') != std::string::npos)
	{
		num = std::stod(src);
		return DOUBLE;
	}
	else
	{
		num = std::stoi(src);
		return INT;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout	<< "invalid arguments number"
					<< std::endl;
		return 0;
	}
	std::string	src(argv[1]);
	double		num;
	e_type		type;
	try
	{
		type = get_type(num, src);
		std::cout << type << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout	<< "char: impossible\n"
					<< "int: impossible\n"
					<< "float: impossible\n"
					<< "double: impossible\n";
	}
}
//switch char->int->float->double?
