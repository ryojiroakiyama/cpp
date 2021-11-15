#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	public:
		Animal();
		Animal( const Animal& original );
		virtual ~Animal();
		Animal&			operator= ( const Animal& right );
		virtual void	makeSound() const;
		std::string		getType( void ) const;
	protected:
		void			setType( std::string type_arg );
	private:
		std::string		type;
};

#endif
