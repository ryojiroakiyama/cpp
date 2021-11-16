#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define MNUM 4

class Character : public ICharacter
{
	public:
		Character();
		Character( const std::string& name );
		Character( const Character& original );
		virtual ~Character();
		Character&					operator=( const Character& right );
		virtual std::string const&	getName() const;
		virtual void				equip( AMateria* );
		virtual void				unequip( int idx );
		virtual void				use( int idx, ICharacter& target );
	private:
		std::string	_Name;
		AMateria*	_Materia[MNUM];
};

#endif
