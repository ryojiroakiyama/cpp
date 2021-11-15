#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Cat : public virtual Animal
{
	public:
		Cat();
		Cat( const Cat& original );
		virtual ~Cat();
		Cat&			operator= ( const Cat& right );
		virtual void	makeSound() const;
};

#endif
