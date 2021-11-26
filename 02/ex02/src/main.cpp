#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << "---------------extra test" << std::endl;
	{
		Fixed a( Fixed(10) / Fixed(1) );
		Fixed b( Fixed(2) / Fixed(-1) );
		std::cout << "a : " << a << std::endl;
		std::cout << "b : " << b << std::endl;
		std::cout << "min : " << Fixed::min( a, b ) << std::endl;
		Fixed e(6.04f);
		Fixed f(6.04f);
		std::cout << "6.04f +  6.04f : " << (e + f) << std::endl;
		std::cout << "6.04f -  6.04f : " << (e - f) << std::endl;
		std::cout << "6.04f != 6.04f : " << (e != f) << std::endl;
		//Fixed(2f) / Fixed(1f)
		//--a
		//--b
		try
		{
			Fixed a( Fixed(2) / Fixed() );
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
