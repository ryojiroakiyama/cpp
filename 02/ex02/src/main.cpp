#include <iostream>
#include "Fixed.hpp"

int main( void )
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

	//Fixed c( Fixed(2) / Fixed() );
	//std::cout << "c : " << c << std::endl;
	//Fixed d( Fixed(2) / Fixed(-1) );
	//std::cout << "d : " << d << std::endl;
	//std::cout << "min : " << Fixed::min( c, d ) << std::endl;
	//Fixed e(6.04f);
	//Fixed f(6.04f);
	//std::cout << "6.04f +  6.04f : " << (e + f) << std::endl;
	//std::cout << "6.04f -  6.04f : " << (e - f) << std::endl;
	//std::cout << "6.04f != 6.04f : " << (e != f) << std::endl;
	//Fixed(2f) / Fixed(1f)
	//--a
	//--b
	return 0;
}
