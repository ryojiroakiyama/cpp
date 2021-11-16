#include "Dog.hpp"

// construcor, destructor
Dog::Dog()
{
	std::cout	<< "Dog default constructor"
				<< std::endl;
	setType("Dog");
	_Brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
	delete _Brain;
}

Dog::Dog( const Dog& original )
{
	std::cout	<< "Dog copy constructor"
				<< std::endl;
	_Brain = new Brain();
	*this = original;
}

// oprator overload
Dog&	Dog::operator= ( const Dog& right )
{
	setType(right.getType());
	*_Brain = *(right._Brain);
	return *this;
}

// function
void	Dog::makeSound() const
{
	std::cout	<< "bow-wow!"
				<< std::endl;
}

void	Dog::setBrain( const std::string idea, const int idx )
{
	_Brain->setIdea(idea, idx);
}

void	Dog::displayBrain()
{
	_Brain->displayIdeas();
}
