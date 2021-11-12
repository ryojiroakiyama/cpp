#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_FixBit = 8;

// constructor, destructor
Fixed::Fixed() : _InternalValue(0) {}
Fixed::Fixed( const int value ) { _InternalValue = value << _FixBit; }
Fixed::Fixed( const float value ) { _InternalValue = roundf(value * std::pow(2, 8)); }
Fixed::~Fixed() {}
Fixed::Fixed( const Fixed& original ) { *this = original; }

// basic method
int		Fixed::getRawBits( void ) const { return _InternalValue; }
void	Fixed::setRawBits( int const raw ) { _InternalValue = raw; }
float	Fixed::toFloat( void ) const { return static_cast<float>(_InternalValue) / (1 << _FixBit); }
int		Fixed::toInt( void ) const { return _InternalValue >> _FixBit; }

// overload operator
Fixed&	Fixed::operator= ( const Fixed& right ) { _InternalValue = right.getRawBits(); return *this; }
bool	Fixed::operator> ( const Fixed& right ) const { return _InternalValue > right.getRawBits(); }
bool	Fixed::operator< ( const Fixed& right ) const { return _InternalValue < right.getRawBits(); }
bool	Fixed::operator>=( const Fixed& right ) const { return _InternalValue >= right.getRawBits(); }
bool	Fixed::operator<=( const Fixed& right ) const { return _InternalValue <= right.getRawBits(); }
bool	Fixed::operator==( const Fixed& right ) const { return _InternalValue == right.getRawBits(); }
bool	Fixed::operator!=( const Fixed& right ) const { return _InternalValue != right.getRawBits(); }
Fixed	Fixed::operator+ ( const Fixed& right ) const { return Fixed(_InternalValue + right.getRawBits()); }
Fixed	Fixed::operator- ( const Fixed& right ) const { return Fixed(_InternalValue - right.getRawBits()); }
Fixed	Fixed::operator* ( const Fixed& right ) const { return Fixed(_InternalValue * right.getRawBits()); }
Fixed	Fixed::operator/ ( const Fixed& right ) const { return Fixed(_InternalValue / right.getRawBits()); }
Fixed&	Fixed::operator++() { _InternalValue++; return *this; }
Fixed	Fixed::operator++(int) { Fixed original = *this; ++(*this); return original; }

// min, max
Fixed&			Fixed::min( Fixed& a, Fixed& b )
{
	if (a > b)
		return a;
	return a;
}

const Fixed&	Fixed::min( const Fixed& a, const Fixed& b )
{
	if (a > b)
		return b;
	return a;
}

Fixed&			Fixed::max( Fixed& a, Fixed& b )
{
	if (a < b)
		return b;
	return a;
}

const Fixed& 	Fixed::max( const Fixed& a, const Fixed& b )
{
	if (a < b)
		return b;
	return a;
}

// external function
std::ostream&	operator<<( std::ostream& os, const Fixed& right )
{
	os << right.toFloat();
	return os;
}
