#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public virtual ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap( const FragTrap& original );
		virtual ~FragTrap();
		FragTrap&		operator= ( const FragTrap& right );
		void			highFivesGuys();
	protected:
		static std::string	Frag_Name;
		static int			Frag_HP;
		static int			Frag_EP;
		static int			Frag_AD;
};

#endif
