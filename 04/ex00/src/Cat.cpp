#include "Cat.hpp"

// construcor, destructor
Cat::Cat()
{
	setType("Cat");
	std::cout	<< "Cat default constructor"
				<< " [" << getType() << "]"
				<< std::endl;
}

Cat::~Cat() { std::cout << "Cat destructor" << std::endl; }
Cat::Cat( const Cat& original ) { *this = original; }

// oprator overload
Cat&	Cat::operator= ( const Cat& right )
{
	setType(right.getType());
	return *this;
}

// function
void	Cat::makeSound() const
{
	std::cout	<< "meow!"
				<< std::endl;
}
