#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_FixBit = 8;

// constructor, destructor
Fixed::Fixed() : _InternalValue(0) {}
Fixed::Fixed( const int value ) : _InternalValue(value * (1 << _FixBit)) {}
Fixed::Fixed( const float value ) : _InternalValue(roundf(value * (1 << _FixBit))) {}
Fixed::~Fixed() {}
Fixed::Fixed( const Fixed& original ) { *this = original; }

// basic method
int		Fixed::getRawBits( void ) const { return _InternalValue; }
void	Fixed::setRawBits( int const raw ) { _InternalValue = raw; }
float	Fixed::toFloat( void ) const { return static_cast<float>(_InternalValue) / (1 << _FixBit); }
int		Fixed::toInt( void ) const { return _InternalValue / (1 << _FixBit); }

// overload operator
Fixed&	Fixed::operator= ( const Fixed& right ) { _InternalValue = right.getRawBits(); return *this; }
bool	Fixed::operator> ( const Fixed& right ) const { return _InternalValue > right.getRawBits(); }
bool	Fixed::operator< ( const Fixed& right ) const { return _InternalValue < right.getRawBits(); }
bool	Fixed::operator>=( const Fixed& right ) const { return _InternalValue >= right.getRawBits(); }
bool	Fixed::operator<=( const Fixed& right ) const { return _InternalValue <= right.getRawBits(); }
bool	Fixed::operator==( const Fixed& right ) const { return _InternalValue == right.getRawBits(); }
bool	Fixed::operator!=( const Fixed& right ) const { return _InternalValue != right.getRawBits(); }

Fixed	Fixed::operator+ ( const Fixed& right ) const
{
	Fixed	result;
	result.setRawBits(_InternalValue + right.getRawBits());
	return result;
}

Fixed	Fixed::operator- ( const Fixed& right ) const
{
	Fixed	result;
	result.setRawBits(_InternalValue - right.getRawBits());
	return result;
}

Fixed	Fixed::operator* ( const Fixed& right ) const
{
	Fixed	result;
	long	left_num = this->getRawBits();
	long	right_num = right.getRawBits();
	result.setRawBits(static_cast<int>((left_num * right_num) / (1 << _FixBit)));
	return result;
}

Fixed	Fixed::operator/ ( const Fixed& right ) const
{
	Fixed	result;
	if (!(right.getRawBits()))
	{
		std::cout << "0 divide detected!" << std::endl;
		result.setRawBits(0);
	}
	else
		result.setRawBits((_InternalValue / right.getRawBits()) * (1 << _FixBit));
	return result;
}

Fixed&	Fixed::operator++()
{
	_InternalValue++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed original = *this;
	++(*this);
	return original;
}

// min, max
Fixed&			Fixed::min( Fixed& a, Fixed& b )
{
	if (a > b)
		return b;
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
