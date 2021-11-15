#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap( const ScavTrap& original );
		virtual ~ScavTrap();
		ScavTrap&		operator= ( const ScavTrap& right );
		virtual void	attack( std::string const & target );
		void			guardGate();
	protected:
		static std::string	Scav_Name;
		static int			Scav_HP;
		static int			Scav_EP;
		static int			Scav_AD;
};

#endif
