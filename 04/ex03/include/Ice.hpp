#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>

class ICharacter;
class AMateria;

class Ice : public AMateria
{
	public:
		Ice();
		Ice( std::string const & type );
		virtual ~Ice();
		Ice&				operator=( const Ice& right );
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};

#endif
