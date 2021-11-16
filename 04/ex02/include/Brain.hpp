#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain
{
	public:
		Brain();
		Brain( const Brain& original );
		virtual ~Brain();
		Brain&				operator= ( const Brain& right );
		std::string			getIdea( const int idx );
		void				displayIdeas();
		void				setIdea( const std::string src, const int idx );
	private:
		std::string			_ideas[100];
};

#endif
