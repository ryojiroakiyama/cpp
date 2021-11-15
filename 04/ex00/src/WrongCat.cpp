#include "WrongCat.hpp"

// construcor, destructor
WrongCat::WrongCat()
{
	setType("WrongCat");
	std::cout	<< "WrongCat default constructor"
				<< " [" << getType() << "]"
				<< std::endl;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor" << std::endl; }
WrongCat::WrongCat( const WrongCat& original ) { *this = original; }

// oprator overload
WrongCat&	WrongCat::operator= ( const WrongCat& right )
{
	setType(right.getType());
	return *this;
}

// function
void	WrongCat::makeSound() const
{
	std::cout	<< "kyan kyan kyan kyan!"
				<< std::endl;
}
