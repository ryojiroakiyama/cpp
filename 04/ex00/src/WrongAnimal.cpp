#include "WrongAnimal.hpp"

// construcor, destructor
WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout	<< "WrongAnimal default constructor"
				<< " [" << type << "]"
				<< std::endl;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor" << std::endl; }
WrongAnimal::WrongAnimal( const WrongAnimal& original ) { *this = original; }

// oprator overload
WrongAnimal&	WrongAnimal::operator= ( const WrongAnimal& right )
{
	type = right.getType();
	return *this;
}

// getter, setter
std::string		WrongAnimal::getType( void ) const { return type; }
void			WrongAnimal::setType( std::string type_arg ) { type = type_arg; }

// function
void			WrongAnimal::makeSound() const
{
	std::cout	<< "ooooooh! Wrong Animal!"
				<< std::endl;
}
