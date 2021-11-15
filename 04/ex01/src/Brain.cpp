#include "Brain.hpp"

// construcor, destructor
Brain::Brain()
{
	std::cout	<< "Brain default constructor"
				<< std::endl;
}

Brain::~Brain() { std::cout << "Brain destructor" << std::endl; }
Brain::Brain( const Brain& original ) { *this = original; }

// oprator overload
Brain&	Brain::operator= ( const Brain& right )
{
	// string copy
	return *this;
}
