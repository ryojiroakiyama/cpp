#ifndef KAREN_HPP
#define KAREN_HPP
#include <iostream>

class	Karen
{
	public:
		Karen();
		void	complain(std::string level);
	private:
		void	(Karen::*functions[5])(void);
		void	non(void);
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif
