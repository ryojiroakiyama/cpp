#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_FixBit = 8;

Fixed::Fixed() : _InternalValue(0) {}
Fixed::Fixed( const int value ) { _InternalValue = value << _FixBit; }
Fixed::Fixed( const float value ) { _InternalValue = roundf(value * std::pow(2, 8)); }
Fixed::~Fixed() {}
Fixed::Fixed( const Fixed& original ) { *this = original; }

int		Fixed::getRawBits( void ) const { return _InternalValue; }
void	Fixed::setRawBits( int const raw ) { _InternalValue = raw; }
float	Fixed::toFloat( void ) const { return static_cast<float>(_InternalValue) / (1 << _FixBit); }
int		Fixed::toInt( void ) const { return _InternalValue >> _FixBit; }

Fixed&	Fixed::operator=( const Fixed& right )
{
	_InternalValue = right._InternalValue;
	return *this;
}

bool	Fixed::operator>( const Fixed& right ) { return _InternalValue > right.getRawBits(); }
bool	Fixed::operator<( const Fixed& right ) { return _InternalValue < right.getRawBits(); }
bool	Fixed::operator>=( const Fixed& right ) { return _InternalValue >= right.getRawBits(); }
bool	Fixed::operator<=( const Fixed& right ) { return _InternalValue <= right.getRawBits(); }
bool	Fixed::operator==( const Fixed& right ) { return _InternalValue == right.getRawBits(); }
bool	Fixed::operator!=( const Fixed& right ) { return _InternalValue != right.getRawBits(); }
Fixed	Fixed::operator+( const Fixed& right ) { return Fixed(_InternalValue + right.getRawBits()); }
Fixed	Fixed::operator-( const Fixed& right ) { return Fixed(_InternalValue - right.getRawBits()); }
Fixed	Fixed::operator*( const Fixed& right ) { return Fixed(_InternalValue * right.getRawBits()); }
Fixed	Fixed::operator/( const Fixed& right ) { return Fixed(_InternalValue / right.getRawBits()); }

std::ostream&	operator<<( std::ostream& os, const Fixed& right )
{
	os << right.toFloat();
	return os;
}
