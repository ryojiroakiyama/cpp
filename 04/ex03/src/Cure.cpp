#include "ICharacter.hpp"
#include "Cure.hpp"

// construcor, destructor
Cure::Cure()
{
	std::cout	<< "Cure default constructor"
				<< std::endl;
	_Type = "cure";
}

Cure::Cure( std::string const & type )
{
	std::cout	<< "Cure constructor"
				<< std::endl;
	_Type = type;
}

Cure::Cure( const Cure& original )
{
	std::cout	<< "Cure copy constructor"
				<< std::endl;
	*this = original;
}

Cure::~Cure()
{
	std::cout	<< "Cure default destructor"
				<< std::endl;
}

// oprator overload
Cure&			Cure::operator= ( const Cure& right )
{
	_Type = right._Type;
	return *this;
}

// function
AMateria*		Cure::clone() const
{
	return new Cure(*this);
}

void 			Cure::use(ICharacter& target)
{
	std::cout	<< "* heals "
				<< target.getName()
				<< "’s wounds *"
				<< std::endl;
}
