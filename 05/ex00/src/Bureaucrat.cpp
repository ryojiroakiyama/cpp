#include "Bureaucrat.hpp"

// constructor, destructor
Bureaucrat::Bureaucrat() : _Name("B"), _Grade(150)
{
	std::cout	<< "Bureaucrat default constructor"
				<< std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _Name(name), _Grade(grade)
{
	std::cout	<< "Bureaucrat constructor"
				<< std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout	<< "Bureaucrat default destructor"
				<< std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& original )
{
	*this = original;
}

// overload operator
Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& right )
{
	_Name = right._Name;
	_Grade = right._Grade;
	return *this;
}

//bool	Bureaucrat::operator> ( const Bureaucrat& right ) const { return _RawBits > right.getRawBits(); }
//bool	Bureaucrat::operator< ( const Bureaucrat& right ) const { return _RawBits < right.getRawBits(); }
//bool	Bureaucrat::operator>=( const Bureaucrat& right ) const { return _RawBits >= right.getRawBits(); }
//bool	Bureaucrat::operator<=( const Bureaucrat& right ) const { return _RawBits <= right.getRawBits(); }
//bool	Bureaucrat::operator==( const Bureaucrat& right ) const { return _RawBits == right.getRawBits(); }
//bool	Bureaucrat::operator!=( const Bureaucrat& right ) const { return _RawBits != right.getRawBits(); }

//Bureaucrat	Bureaucrat::operator+ ( const Bureaucrat& right ) const
//{
//	Bureaucrat	result;
//	result.setRawBits(_RawBits + right.getRawBits());
//	return result;
//}

//Bureaucrat	Bureaucrat::operator- ( const Bureaucrat& right ) const
//{
//	Bureaucrat	result;
//	result.setRawBits(_RawBits - right.getRawBits());
//	return result;
//}

//Bureaucrat	Bureaucrat::operator* ( const Bureaucrat& right ) const
//{
//	Bureaucrat	result;
//	long	left_num = this->getRawBits();
//	long	right_num = right.getRawBits();
//	result.setRawBits(static_cast<int>((left_num * right_num) / (1 << _FixBit)));
//	return result;
//}

//Bureaucrat	Bureaucrat::operator/ ( const Bureaucrat& right ) const
//{
//	Bureaucrat	result;
//	if (!(right.getRawBits()))
//	{
//		std::cout << "0 divide detected!" << std::endl;
//		result.setRawBits(0);
//	}
//	else
//		result.setRawBits((_RawBits / right.getRawBits()) * (1 << _FixBit));
//	return result;
//}

//Bureaucrat&	Bureaucrat::operator++()
//{
//	_RawBits++;
//	return *this;
//}

//Bureaucrat	Bureaucrat::operator++(int)
//{
//	Bureaucrat original = *this;
//	++(*this);
//	return original;
//}

// external function
std::ostream&	operator<<( std::ostream& os, const Bureaucrat& right )
{
	os	<< "<" << right.getName() << ">"
		<< ", bureaucrat grade "
		<< "<" << right.getGrade() << ">.";
	return os;
}
