#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public virtual Animal
{
	public:
		Cat();
		Cat( const Cat& original );
		virtual ~Cat();
		Cat&			operator= ( const Cat& right );
		virtual void	makeSound() const;
	private:
		Brain			*_Brain;
};

#endif
