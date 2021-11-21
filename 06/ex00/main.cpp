#include <iostream>
#include <iomanip>


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
#define IMPOSSIBLE "impossible"
#define NODISPLAY "Non displayable"

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

void	putChar(char num, bool possible)
{
	if (possible)
	{
		if (isprint(num))
			std::cout	<< C << "'" << num << "'" << std::endl;
		else
			std::cout	<< C << NODISPLAY << std::endl;
	}
	else
		std::cout	<< C << IMPOSSIBLE << std::endl;
}

void	putInt(int num, bool possible)
{
	if (possible)
		std::cout	<< I << num << std::endl;
	else
		std::cout	<< I << IMPOSSIBLE << std::endl;
}

void	putFloat(float num, int precision, bool possible)
{
	if (possible)
		std::cout	<< std::fixed << std::setprecision(precision)
					<< F << num << "f" << std::endl;
	else
		std::cout	<< F << IMPOSSIBLE << std::endl;
}

void	putDouble(double num, int precision, bool possible)
{
	if (possible)
		std::cout	<< std::fixed << std::setprecision(precision)
					<< D << num << std::endl;
	else
		std::cout	<< D << IMPOSSIBLE << std::endl;
}

void	ItoC(int num)
{
	if (num < static_cast<int>(CMIN) || static_cast<int>(CMAX) < num)
		putChar(num, false);
	else
		putChar(static_cast<char>(num), true);
}

void	FtoC(float num)
{
	if (num < static_cast<float>(CMIN) || static_cast<float>(CMAX) < num)
		putChar(num, false);
	else
		putChar(static_cast<char>(num), true);
}

void	FtoI(float num)
{
	if (num < static_cast<float>(IMIN) || static_cast<float>(IMAX) < num)
		putInt(num, false);
	else
		putInt(static_cast<int>(num), true);
}

void	DtoC(double num)
{
	if (num < static_cast<double>(CMIN) || static_cast<double>(CMAX) < num)
		putChar(num, false);
	else
		putChar(static_cast<char>(num), true);
}

void	DtoI(double num)
{
	if (num < static_cast<double>(IMIN) || static_cast<double>(IMAX) < num)
		putInt(num, false);
	else
		putInt(static_cast<int>(num), true);
}

void	DtoF(double num, int precision)
{
	if (num < static_cast<double>(FMIN) || static_cast<double>(FMAX) < num)
		putFloat(num, precision, false);
	else
		putFloat(static_cast<float>(num), precision, true);
}

int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw "invalid arguments number";
		std::string	src(argv[1]);
		e_type		type = getType(src);
		int			precision;
		if (type == CHAR)
		{
			int num = static_cast<int>(src.at(0));
			precision = 1;
			putChar(src.at(0), true);
			putInt(num, true);
			putFloat(num, precision, true);
			putDouble(num, precision, true);
		}
		else if (type == INT)
		{
			int num = std::stoi(src);
			precision = 1;
			ItoC(num);
			putInt(num, true);
			putFloat(num, precision, true);
			putDouble(num, precision, true);
		}
		else if (type == FLOAT)
		{
			float num = std::stof(src);
			precision = src.size() - src.find('.') - 1;
			FtoC(num);
			FtoI(num);
			putFloat(num, precision, true);
			putDouble(num, precision, true);
		}
		else if (type == FLOAT_PSEUDO)
		{
			float num = std::stof(src);
			precision = 0;
			putChar(num, false);
			putInt(num, false);
			putFloat(num, precision, true);
			putDouble(num, precision, true);
		}
		else if (type == DOUBLE)
		{
			double num = std::stod(src);
			precision = src.size() - src.find('.') - 1;
			DtoC(num);
			DtoI(num);
			DtoF(num, precision);
			putDouble(num, precision, true);
		}
		else
		{
			float num = std::stof(src);
			precision = 0;
			putChar(num, false);
			putInt(num, false);
			DtoF(num, precision);
			putDouble(num, precision, true);
		}
	}
	catch(const char *message)
	{
		std::cerr	<< message
					<< std::endl;
	}
	catch(const std::exception& e)
	{
		putChar(0, false);
		putInt(0, false);
		putFloat(0, 0, false);
		putDouble(0, 0, false);
	}
}
