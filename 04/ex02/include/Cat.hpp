#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	public:
		Cat();
		Cat( const Cat& original );
		virtual ~Cat();
		Cat&			operator= ( const Cat& right );
		virtual void	makeSound() const;
		void			setBrain( const std::string idea, const int idx );
		void			displayBrain();
	private:
		Brain			*_Brain;
};

#endif
