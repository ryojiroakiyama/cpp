#include <iostream>
#include <sstream>

#define CMAX std::numeric_limits<char>::max()
#define CMIN std::numeric_limits<char>::min()
#define IMAX std::numeric_limits<int>::max()
#define IMIN std::numeric_limits<int>::min()
#define FMAX std::numeric_limits<float>::max()
#define FMIN std::numeric_limits<float>::min()
#define DMAX std::numeric_limits<double>::max()
#define DMIN std::numeric_limits<double>::min()

#define C "char: "
#define I "int: "
#define F "float: "
#define D "double: "
#define IP "impossible"
#define ND "Non displayable"

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

e_type	get_type(const std::string& src)
{
	if (src == "-inff" || src == "+inff" || src == "nanf")
		return FLOAT_PSEUDO;
	else if (src == "-inf" || src == "+inf" || src == "nan")
		return DOUBLE_PSEUDO;
	else if (src.size() == 1 && !isdigit(src.at(0)) && isprint(src.at(0)))
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
		e_type		type = get_type(src);
		std::cout << type << std::endl;
		if (type == CHAR)
		{
			int num = static_cast<int>(src.at(0));
			std::cout	<< C << src.at(0) << std::endl;
			std::cout	<< I << num << std::endl;
			std::cout	<< F << num << ".0f" << std::endl;
			std::cout	<< D << num << ".0" << std::endl;
		}
		else if (type == INT)
		{
			int num = std::stoi(src);
			if (num < static_cast<int>(CMIN) || static_cast<int>(CMAX) < num)
				std::cout	<< C << IP << std::endl;
			else if (isprint(num))
				std::cout	<< C << static_cast<char>(num) << std::endl;
			else
				std::cout	<< C << ND << std::endl;
			std::cout	<< I << num << std::endl;
			std::cout	<< F << num << ".0f" << std::endl;
			std::cout	<< D << num << ".0" << std::endl;
		}
	}
	catch(const char *message)
	{
		std::cerr	<< message
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout	<< C << IP << std::endl
					<< I << IP << std::endl
					<< F << IP << std::endl
					<< D << IP << std::endl;
	}
}
//switch char->int->float->double?
