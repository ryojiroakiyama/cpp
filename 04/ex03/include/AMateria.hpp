#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria( std::string const& type );
		AMateria( const AMateria& original );
		virtual ~AMateria();
		AMateria&			operator=( const AMateria& right );
		std::string const &	getType() const;
		virtual AMateria* 	clone() const = 0;
		virtual void 		use(ICharacter& target);
	protected:
		std::string	_Type;
};

#endif
