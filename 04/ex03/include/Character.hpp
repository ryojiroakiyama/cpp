#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character( std::string const & type );
		virtual ~Character();
		Character&					operator=( const Character& right );
		virtual std::string const &	getName() const;
		virtual void				equip(AMateria*);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};

#endif
