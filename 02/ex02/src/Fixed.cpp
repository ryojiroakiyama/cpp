#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// constructor, destructor
Fixed::Fixed() : _RawBits(0) {}
Fixed::Fixed( const int value ) : _RawBits(value * (1 << _FixBit)) {}
Fixed::Fixed( const float value ) : _RawBits(static_cast<int>(std::roundf(value * (1 << _FixBit)))) {}
Fixed::~Fixed() {}
Fixed::Fixed( const Fixed& original ) { *this = original; }

// basic method
int		Fixed::getRawBits( void ) const { return _RawBits; }
void	Fixed::setRawBits( int const raw ) { _RawBits = raw; }
float	Fixed::toFloat( void ) const { return static_cast<float>(_RawBits) / (1 << _FixBit); }
int		Fixed::toInt( void ) const { return _RawBits / (1 << _FixBit); }

// overload operator
Fixed&	Fixed::operator= ( const Fixed& right ) { _RawBits = right.getRawBits(); return *this; }
bool	Fixed::operator> ( const Fixed& right ) const { return _RawBits > right.getRawBits(); }
bool	Fixed::operator< ( const Fixed& right ) const { return _RawBits < right.getRawBits(); }
bool	Fixed::operator>=( const Fixed& right ) const { return _RawBits >= right.getRawBits(); }
bool	Fixed::operator<=( const Fixed& right ) const { return _RawBits <= right.getRawBits(); }
bool	Fixed::operator==( const Fixed& right ) const { return _RawBits == right.getRawBits(); }
bool	Fixed::operator!=( const Fixed& right ) const { return _RawBits != right.getRawBits(); }

Fixed	Fixed::operator+ ( const Fixed& right ) const
{
	Fixed	result;
	result.setRawBits(_RawBits + right.getRawBits());
	return result;
}

Fixed	Fixed::operator- ( const Fixed& right ) const
{
	Fixed	result;
	result.setRawBits(_RawBits - right.getRawBits());
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
		throw std::exception();
	long	left_num = this->getRawBits();
	long	right_num = right.getRawBits();
	result.setRawBits(static_cast<int>((left_num / right_num) * (1 << _FixBit)));
	return result;
}

Fixed&	Fixed::operator++()
{
	_RawBits++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed original = *this;
	++(*this);
	return original;
}

Fixed&	Fixed::operator--()
{
	_RawBits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed original = *this;
	--(*this);
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
