#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( const ClapTrap& original );
		virtual ~ClapTrap();
		ClapTrap&		operator= ( const ClapTrap& right );
		virtual void	attack( std::string const & target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );
		std::string		getName( void ) const;
		unsigned int	getHitPoints( void ) const;
		unsigned int	getEnergyPoints( void ) const;
		unsigned int	getAttackDamage( void ) const;
	protected:
		void			setName( std::string name );
		void			setHitPoints( unsigned int num );
		void			setEnergyPoints( unsigned int num );
		void			setAttackDamage( unsigned int num );
	private:
		std::string		_Name;
		unsigned int	_HitPoints;
		unsigned int	_EnergyPoints;
		unsigned int	_AttackDamage;
};

#endif
