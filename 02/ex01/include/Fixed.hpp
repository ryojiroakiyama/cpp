#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
	public:
		Fixed();
		Fixed( const int value );
		Fixed( const float value );
		~Fixed();
		Fixed( const Fixed& src );
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;
		Fixed&				operator=( const Fixed& src );
	private:
		int					_RawBits;
		static const int	_FixBit = 8;
};

std::ostream&	operator<<( std::ostream& os, const Fixed& src );

#endif
