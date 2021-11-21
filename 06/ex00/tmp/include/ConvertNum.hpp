#ifndef CONVERTNUM_HPP
#define CONVERTNUM_HPP

#include <iostream>
#define _NOEXCEPT throw()

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

enum e_status
{
	DISPLAYABLE,
	NODISPLAYABLE,
	IMPOSSIBLE,
	STATUS_NUM
};

class ConvertNum
{
	public:
		ConvertNum();
		~ConvertNum();
		ConvertNum( const ConvertNum& original );
		ConvertNum&			operator= ( const ConvertNum& right );
		std::string	const&	getSrcString() const;
	private:
		e_type				_Type;
		char				_Char;
		int					_Int;
		float				_Float;
		double				_Double;
		e_status			_CharStatus;
		e_status			_IntStatus;
		e_status			_FloatStatus;
		e_status			_DoubleStatus;
		static const char	_CharMax;
		static const char	_CharMin;
		static const int	_IntMax;
		static const int	_IntMin;
		static const float	_FloatMax;
		static const float	_FloatMin;
		static const double	_DoubleMax;
		static const double	_DoubleMin;
};

std::ostream&	operator<<( std::ostream& os, const ConvertNum& right );

#endif
