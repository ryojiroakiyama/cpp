#include <iostream>
#include <sstream>
#include <iomanip>

#define CMAX static_cast<double>(std::numeric_limits<char>::max())
#define CMIN static_cast<double>(std::numeric_limits<char>::min())
#define IMAX static_cast<double>(std::numeric_limits<int>::max())
#define IMIN static_cast<double>(std::numeric_limits<int>::min())
#define FMAX static_cast<double>(std::numeric_limits<float>::max())
#define FNAN std::numeric_limits<float>::quiet_NaN()
#define FINF std::numeric_limits<float>::infinity()
#define DNAN std::numeric_limits<double>::quiet_NaN()
#define DINF std::numeric_limits<double>::infinity()

#define IMPOSSIBLE "impossible"
#define NODISPLAY "Non displayable"
#define TITLE_W 8

enum e_type
{
	/*0*/CHAR,
	/*1*/INT,
	/*2*/FLOAT,
	/*3*/FLOAT_NAN,
	/*4*/FLOAT_PINF,
	/*5*/FLOAT_NINF,
	/*6*/DOUBLE,
	/*7*/DOUBLE_NAN,
	/*8*/DOUBLE_PINF,
	/*9*/DOUBLE_NINF,
	/*10*/TYPE_NUM
};

e_type	getType(const std::string& src)
{
	if (src == "nanf")
		return FLOAT_NAN;
	else if (src == "+inff")
		return FLOAT_PINF;
	else if (src == "-inff")
		return FLOAT_NINF;
	else if (src == "nan")
		return DOUBLE_NAN;
	else if (src == "+inf")
		return DOUBLE_PINF;
	else if (src == "-inf")
		return DOUBLE_NINF;
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

int	ft_stoi(const char *src)
{
	double get;

	get = std::atof(src);
	if (get < IMIN || IMAX < get)
		throw std::exception();
	return static_cast<int>(get);
}

float	ft_stof(const char *src)
{
	double get;

	get = std::atof(src);
	if (get < -FMAX || FMAX < get)
		throw std::exception();
	return static_cast<float>(get);
}

double	ft_stod(const char *src)
{
	double get;

	get = std::atof(src);
	return (get);
}

int main(int argc, char *argv[])
{
	try
	{
		if (argc != 2)
			throw "invalid arguments number";
		std::string			src(argv[1]);
		e_type				type = getType(src);
		int					precision;
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
			int num = ft_stoi(argv[1]);
			precision = 1;
			ItoC(num);
			putInt(num, true);
			putFloat(num, precision, true);
			putDouble(num, precision, true);
		}
		else if (type == FLOAT)
		{
			float num = ft_stof(argv[1]);
			precision = 1;
			if (src.find('.') != std::string::npos)
				precision = src.size() - src.find('.') - 2;
			FtoC(num);
			FtoI(num);
			putFloat(num, precision, true);
			putDouble(num, precision, true);
		}
		else if (FLOAT_NAN <= type && type <= FLOAT_NINF)
		{
			float num = 0;
			if (type == FLOAT_NAN)
				num = FNAN;
			else if (type == FLOAT_PINF)
				num = FINF;
			else if (type == FLOAT_NINF)
				num = -FINF;
			precision = 0;
			putChar(num, false);
			putInt(num, false);
			putFloat(num, precision, true);
			putDouble(num, precision, true);
		}
		else if (type == DOUBLE)
		{
			double num = ft_stod(argv[1]);
			precision = src.size() - src.find('.') - 1;
			DtoC(num);
			DtoI(num);
			DtoF(num, precision);
			putDouble(num, precision, true);
		}
		else if (DOUBLE_NAN <= type && type <= DOUBLE_NINF)
		{
			double num = 0;
			if (type == DOUBLE_NAN)
				num = DNAN;
			else if (type == DOUBLE_PINF)
				num = DINF;
			else if (type == DOUBLE_NINF)
				num = -DINF;
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
