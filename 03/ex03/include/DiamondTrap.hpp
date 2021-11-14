#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap( const DiamondTrap& original );
		virtual ~DiamondTrap();
		DiamondTrap&	operator= ( const DiamondTrap& right );
		void			whoAmI();
	private:
		std::string		_Name;
};

#endif
