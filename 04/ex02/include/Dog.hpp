#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	public:
		Dog();
		Dog( const Dog& original );
		virtual ~Dog();
		Dog&			operator= ( const Dog& right );
		virtual void	makeSound() const;
		void			setBrain( const std::string idea, const int idx );
		void			displayBrain();
	private:
		Brain			*_Brain;
};

#endif
