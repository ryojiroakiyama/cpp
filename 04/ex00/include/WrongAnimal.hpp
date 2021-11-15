#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal& original );
		virtual ~WrongAnimal();
		WrongAnimal&	operator= ( const WrongAnimal& right );
		void			makeSound() const;
		std::string		getType( void ) const;
	protected:
		void			setType( std::string type_arg );
	private:
		std::string		type;
};

#endif
