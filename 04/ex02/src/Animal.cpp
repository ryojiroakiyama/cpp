#include "Animal.hpp"

// construcor, destructor
Animal::Animal() : type("Animal")
{
	std::cout	<< "Animal default constructor"
				<< std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor" << std::endl; }
Animal::Animal( const Animal& original ) { *this = original; }

// oprator overload
Animal&	Animal::operator= ( const Animal& right )
{
	type = right.getType();
	return *this;
}

// getter, setter
std::string		Animal::getType( void ) const { return type; }
void			Animal::setType( std::string type_arg ) { type = type_arg; }
