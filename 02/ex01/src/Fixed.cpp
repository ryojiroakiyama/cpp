#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_FixBit = 8;

// constructor, destructor
Fixed::Fixed() : _InternalValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value )
{
	std::cout << "Int constructor called" << std::endl;
	_InternalValue = value * (1 << _FixBit);
}

Fixed::Fixed( const float value )
{
	std::cout << "Float constructor called" << std::endl;
	_InternalValue = roundf(value * (1 << _FixBit));
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
	_InternalValue = right.getRawBits();
	return *this;
}

// basic method
int		Fixed::getRawBits( void ) const
{
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
	return _InternalValue / (1 << _FixBit);
}

// external function
std::ostream&	operator<<( std::ostream& os, const Fixed& right )
{
	os << right.toFloat();
	return (os);
}
