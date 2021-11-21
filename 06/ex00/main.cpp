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

e_type	getType(const std::string& src)
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

bool	isSafe_ItoC(int num)
{
	if (num < static_cast<int>(CMIN) || static_cast<int>(CMAX) < num)
		return false;
	return true;
}

bool	isSafe_FtoC(float num)
{
	if (num < static_cast<float>(CMIN) || static_cast<float>(CMAX) < num)
		return false;
	return true;
}

bool	isSafe_FtoI(float num)
{
	if (num < static_cast<float>(IMIN) || static_cast<float>(IMAX) < num)
		return false;
	return true;
}

bool	isSafe_DtoC(double num)
{
	if (num < static_cast<double>(CMIN) || static_cast<double>(CMAX) < num)
		return false;
	return true;
}

bool	isSafe_DtoI(double num)
{
	if (num < static_cast<double>(IMIN) || static_cast<double>(IMAX) < num)
		return false;
	return true;
}

bool	isSafe_DtoF(double num)
{
	if (num < static_cast<double>(FMIN) || static_cast<double>(FMAX) < num)
		return false;
	return true;
}

void	putChar(char num)
{
	if (isprint(num))
		std::cout	<< C << num << std::endl;
	else
		std::cout	<< C << ND << std::endl;
}

int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw "invalid arguments number";
		std::string	src(argv[1]);
		e_type		type = getType(src);
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
			if (isSafe_ItoC(num))
				putChar(static_cast<char>(num));
			else
				std::cout	<< C << IP << std::endl;
			std::cout	<< I << num << std::endl;
			std::cout	<< F << num << ".0f" << std::endl;
			std::cout	<< D << num << ".0" << std::endl;
		}
		else if (type == FLOAT)
		{
			//float num = std::stof(src);
			//if (num < static_cast<float>(CMIN) || )
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
