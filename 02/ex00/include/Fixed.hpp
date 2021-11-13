#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed& src );
		Fixed&				operator=( const Fixed& src );
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
	private:
		int					_InternalValue;
		static const int	_FixBit;
};

#endif
