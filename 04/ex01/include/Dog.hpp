#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public virtual Animal
{
	public:
		Dog();
		Dog( const Dog& original );
		virtual ~Dog();
		Dog&			operator= ( const Dog& right );
		virtual void	makeSound() const;
	private:
		Brain			*_Brain;
};

#endif
