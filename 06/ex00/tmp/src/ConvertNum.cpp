#include "ConvertNum.hpp"

const char		_CharMax = std::numeric_limits<char>::max();
const char		_CharMin = std::numeric_limits<char>::min();
const int		_IntMax = std::numeric_limits<int>::max();
const int		_IntMin = std::numeric_limits<int>::min();
const float		_FloatMax = std::numeric_limits<float>::max();
const float		_FloatMin = std::numeric_limits<float>::min();
const double	_DoubleMax = std::numeric_limits<double>::max();
const double	_DoubleMin = std::numeric_limits<double>::min();

// constructor, destructor

ConvertNum::ConvertNum()
: _Char(0)
, _Int(0)
, _Float(0)
, _Double(0)
, _CharStatus(DISPLAYABLE)
, _IntStatus(DISPLAYABLE)
, _FloatStatus(DISPLAYABLE)
, _DoubleStatus(DISPLAYABLE)
{
	if (src == "-inff" || src == "+inff" || src == "nanf")
		_Type = FLOAT_PSEUDO;
	else if (src == "-inf" || src == "+inf" || src == "nan")
		_Type = DOUBLE_PSEUDO;
	else if (src.size() == 1 && !isdigit(src.at(0)) && isprint(src.at(0)))
		_Type = CHAR;
	else if (src.at(src.size() - 1) == 'f')
		_Type = FLOAT;
	else if (src.find('.') != std::string::npos)
		_Type = DOUBLE;
	else
		_Type = INT;
}

ConvertNum::~ConvertNum() {}

ConvertNum::ConvertNum( const ConvertNum& original )
: ConvertNum(original.getSrcString())
{
	*this = original;
}

// overload operator
ConvertNum&	ConvertNum::operator=( const ConvertNum& right )
{
	_SrcString		= right._SrcString;
	_Type 			= right._Type;
	_Char			= right._Char;
	_Int			= right._Int;
	_Float			= right._Float;
	_Double			= right._Double;
	_CharStatus		= right._CharStatus;
	_IntStatus		= right._IntStatus;
	_FloatStatus	= right._FloatStatus;
	_DoubleStatus	= right._DoubleStatus;
	return *this;
}

std::string const&	ConvertNum::getSrcString() const
{
	return _SrcString;
}

// external function
std::ostream&	operator<<( std::ostream& os, const ConvertNum& right )
{
	os	<< "char: ";
	if ()
	return os;
}
