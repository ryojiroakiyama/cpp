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
	//std::cout << "---------------extra test" << std::endl;
	//{
	//	Fixed a( Fixed(12.0f) / Fixed(1.0f) );
	//	Fixed b( Fixed(2) / Fixed(-1) );
	//	std::cout << "a : " << a << std::endl;
	//	std::cout << "b : " << b << std::endl;
	//	std::cout << "--a : " << --a << std::endl;
	//	std::cout << "a-- : " << a-- << std::endl;
	//	std::cout << "min(" << a << ", " << b << ") : " << Fixed::min( a, b ) << std::endl;
	//	std::cout << "a + b : " << (a + b) << std::endl;
	//	std::cout << "a - b : " << (a - b) << std::endl;
	//	std::cout << "a * b : " << (a * b) << std::endl;
	//	std::cout << "a / b : " << (a / b) << std::endl;
	//	std::cout << "a != b : " << (a != b) << std::endl;
	//	try
	//	{
	//		std::cout << "0 divide -> ";
	//		Fixed a( Fixed(2) / Fixed() );
	//	}
	//	catch(const std::exception& e)
	//	{
	//		std::cerr << e.what() << std::endl;
	//	}
	//}
	return 0;
}
