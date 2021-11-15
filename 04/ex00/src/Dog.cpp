#include "Dog.hpp"

// construcor, destructor
Dog::Dog()
{
	setType("Dog");
	std::cout	<< "Dog default constructor"
				<< " [" << getType() << "]"
				<< std::endl;
}

Dog::~Dog() { std::cout << "Dog destructor" << std::endl; }
Dog::Dog( const Dog& original ) { *this = original; }

// oprator overload
Dog&	Dog::operator= ( const Dog& right )
{
	setType(right.getType());
	return *this;
}

// function
void	Dog::makeSound() const
{
	std::cout	<< "bow-wow!"
				<< std::endl;
}
