#include "ICharacter.hpp"
#include "AMateria.hpp"

// construcor, destructor
AMateria::AMateria()
{
	std::cout	<< "AM default constructor"
				<< std::endl;
}

AMateria::AMateria( std::string const & type ) : _Type(type)
{
	std::cout	<< "AM constructor"
				<< std::endl;
}

AMateria::AMateria( const AMateria& original )
{
	std::cout	<< "AM copy constructor"
				<< std::endl;
	*this = original;
}

AMateria::~AMateria()
{
	std::cout	<< "AM default destructor"
				<< std::endl;
}

// oprator overload
AMateria&			AMateria::operator= ( const AMateria& right )
{
	_Type = right._Type;
	return *this;
}

// function
std::string const &	AMateria::getType() const
{
	return _Type;
}

void 				AMateria::use(ICharacter& target)
{
	std::cout	<< "something"
				<< std::endl;
	(void)target;
}
