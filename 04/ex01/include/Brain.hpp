#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain
{
	public:
		Brain();
		Brain( const Brain& original );
		virtual ~Brain();
		Brain&		operator= ( const Brain& right );
	private:
		std::string	ideas[100];
};

#endif
