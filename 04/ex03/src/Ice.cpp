#include "ICharacter.hpp"
#include "Ice.hpp"

// construcor, destructor
Ice::Ice()
{
	std::cout	<< "Ice default constructor"
				<< std::endl;
	_Type = "ice";
}

Ice::Ice( std::string const & type )
{
	std::cout	<< "Ice constructor"
				<< std::endl;
	_Type = type;
}

Ice::Ice( const Ice& original )
{
	std::cout	<< "Ice copy constructor"
				<< std::endl;
	*this = original;
}

Ice::~Ice()
{
	std::cout	<< "Ice default destructor"
				<< std::endl;
}

// oprator overload
Ice&			Ice::operator= ( const Ice& right )
{
	_Type = right._Type;
	return *this;
}

// function
AMateria*		Ice::clone() const
{
	return new Ice(*this);
}

void 			Ice::use(ICharacter& target)
{
	std::cout	<< "* shoots an ice bolt at "
				<< target.getName()
				<< " *"
				<< std::endl;
}
