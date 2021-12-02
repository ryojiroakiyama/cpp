#include <iostream>
#include <iomanip>

#define CMAX static_cast<double>(std::numeric_limits<char>::max())
#define CMIN static_cast<double>(std::numeric_limits<char>::min())
#define IMAX static_cast<double>(std::numeric_limits<int>::max())
#define IMIN static_cast<double>(std::numeric_limits<int>::min())
#define FMAX static_cast<double>(std::numeric_limits<float>::max())

#define IMPOSSIBLE "impossible"
#define NODISPLAY "Non displayable"
#define TITLE_W 8

enum e_type
{
	/*0*/CHAR,
	/*1*/INT,
	/*2*/FLOAT,
	/*3*/FLOAT_PSEUDO,
	/*4*/DOUBLE,
	/*5*/DOUBLE_PSEUDO,
	/*6*/TYPE_NUM
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
	std::cout	<< std::setw(TITLE_W) << "char: ";
	if (possible)
	{
		if (std::isprint(num))
			std::cout	<< "'" << num << "'";
		else
			std::cout	<< NODISPLAY;
	}
	else
		std::cout	<< IMPOSSIBLE;
	std::cout	<< std::endl;
}

void	putInt(int num, bool possible)
{
	std::cout	<< std::setw(TITLE_W) << "int: ";
	if (possible)
		std::cout	<< num;
	else
		std::cout	<< IMPOSSIBLE;
	std::cout	<< std::endl;
}

void	putFloat(float num, int precision, bool possible)
{
	std::cout	<< std::setw(TITLE_W) << "float: ";
	if (possible)
		std::cout	<< std::fixed << std::setprecision(precision)
					<< num << "f";
	else
		std::cout	<< IMPOSSIBLE;
	std::cout	<< std::endl;
}

void	putDouble(double num, int precision, bool possible)
{
	std::cout	<< std::setw(TITLE_W) << "double: ";
	if (possible)
		std::cout	<< std::fixed << std::setprecision(precision)
					<< num;
	else
		std::cout	<< IMPOSSIBLE;
	std::cout	<< std::endl;
}

void	ItoC(int num)
{
	if (num < CMIN || CMAX < num)
		putChar(num, false);
	else
		putChar(static_cast<char>(num), true);
}

void	FtoC(float num)
{
	if (num < CMIN || CMAX < num)
		putChar(num, false);
	else
		putChar(static_cast<char>(num), true);
}

void	FtoI(float num)
{
	if (num < IMIN || IMAX < num)
		putInt(num, false);
	else
		putInt(static_cast<int>(num), true);
}

void	DtoC(double num)
{
	if (num < CMIN || CMAX < num)
		putChar(num, false);
	else
		putChar(static_cast<char>(num), true);
}

void	DtoI(double num)
{
	if (num < IMIN || IMAX < num)
		putInt(num, false);
	else
		putInt(static_cast<int>(num), true);
}

void	DtoF(double num, int precision)
{
	if (num < -FMAX || FMAX < num)
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
			precision = 1;
			if (src.find('.') != std::string::npos)
				precision = src.size() - src.find('.') - 2;
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
		else if (type == DOUBLE_PSEUDO)
		{
			double num = std::stod(src);
			precision = 0;
			putChar(num, false);
			putInt(num, false);
			putFloat(num, precision, true);
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
