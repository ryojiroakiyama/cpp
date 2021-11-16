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
Brain&		Brain::operator= ( const Brain& right )
{
	for (int idx = 0; idx < 100; idx++)
		_ideas[idx] = right._ideas[idx];
	return *this;
}

// setter, getter
void		Brain::setIdea(const std::string src, const int idx )
{
	_ideas[idx] = src;
}

std::string	Brain::getIdea( const int idx )
{
	return _ideas[idx];
}

// base function
void		Brain::displayIdeas()
{
	for (int idx = 0; idx < 100; idx++)
	{
		std::cout	<< "[" << idx << "] "
					<< _ideas[idx]
					<< std::endl;
	}
}
