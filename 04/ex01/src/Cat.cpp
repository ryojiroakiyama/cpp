#include "Cat.hpp"

// construcor, destructor
Cat::Cat()
{
	std::cout	<< "Cat default constructor"
				<< std::endl;
	setType("Cat");
	_Brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor" << std::endl;
	delete _Brain;
}

Cat::Cat( const Cat& original ) { *this = original; }

// oprator overload
Cat&	Cat::operator= ( const Cat& right )
{
	setType(right.getType());
	// string copy
	return *this;
}

// function
void	Cat::makeSound() const
{
	std::cout	<< "meow!"
				<< std::endl;
}
