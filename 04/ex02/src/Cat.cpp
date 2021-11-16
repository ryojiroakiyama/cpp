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

Cat::Cat( const Cat& original )
{
	std::cout	<< "Cat copy constructor"
				<< std::endl;
	_Brain = new Brain();
	*this = original;
}

// oprator overload
Cat&	Cat::operator= ( const Cat& right )
{
	setType(right.getType());
	*_Brain = *(right._Brain);
	return *this;
}

// function
void	Cat::makeSound() const
{
	std::cout	<< "meow!"
				<< std::endl;
}

void	Cat::setBrain( const std::string idea, const int idx )
{
	_Brain->setIdea(idea, idx);
}

void	Cat::displayBrain()
{
	_Brain->displayIdeas();
}
