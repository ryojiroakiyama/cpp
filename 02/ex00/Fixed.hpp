#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		int			value;
		static int	mantissa;
	private:
		Fixed();
		~Fixed();
		Fixed( Fixed& a );
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );

};

#endif
