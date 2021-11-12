#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_FixBit = 8;

Fixed::Fixed() : _InternalValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	_InternalValue = value << _FixBit;
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	_InternalValue = roundf(value * std::pow(2, 8));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed& original )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed&	Fixed::operator=( const Fixed& right )
{
	std::cout << "Assignation operator called" << std::endl;
	_InternalValue = right._InternalValue;
	return *this;
}

std::ostream&	operator<<( std::ostream& os, const Fixed& right )
{
	os << right.toFloat();
	return (os);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _InternalValue;
}

void	Fixed::setRawBits( int const raw )
{
	_InternalValue = raw;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(_InternalValue) / (1 << _FixBit);
}

int		Fixed::toInt( void ) const
{
	return _InternalValue >> _FixBit;
}
