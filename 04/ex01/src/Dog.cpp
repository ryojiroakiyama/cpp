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

Dog::Dog( const Dog& original ) { *this = original; }

// oprator overload
Dog&	Dog::operator= ( const Dog& right )
{
	setType(right.getType());
	// string copy
	return *this;
}

// function
void	Dog::makeSound() const
{
	std::cout	<< "bow-wow!"
				<< std::endl;
}
