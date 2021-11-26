#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed( const Fixed& src );
		Fixed&	operator=( const Fixed& src );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int					_RawBits;
		static const int	_FixBit = 8;
};

#endif
