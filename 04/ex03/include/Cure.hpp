#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure( std::string const & type );
		Cure( const Cure& original );
		virtual ~Cure();
		Cure&				operator=( const Cure& right );
		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};

#endif
