#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public virtual WrongAnimal
{
	public:
		WrongCat();
		WrongCat( const WrongCat& original );
		virtual ~WrongCat();
		WrongCat&		operator= ( const WrongCat& right );
		virtual void	makeSound() const;
};

#endif
