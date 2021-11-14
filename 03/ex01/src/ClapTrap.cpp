#include "ClapTrap.hpp"
#include <limits.h>

// construcor, destructor
ClapTrap::ClapTrap()
: _Name("ClapTrap player1"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{ std::cout << "default constructor" << std::endl; }

ClapTrap::ClapTrap(std::string name)
: _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{ std::cout << "ClapTrap constructor" << std::endl; }

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor" << std::endl; }
ClapTrap::ClapTrap( const ClapTrap& original ) { *this = original; }

// oprator overload
ClapTrap&	ClapTrap::operator= ( const ClapTrap& right )
{
	_Name 			= right.getName();
	_HitPoints 		= right.getHitPoints();
	_EnergyPoints 	= right.getEnergyPoints();
	_AttackDamage 	= right.getAttackDamage();
	return *this;
}

// getter, setter
std::string		ClapTrap::getName( void ) const { return _Name; }
unsigned int	ClapTrap::getHitPoints( void ) const { return _HitPoints; }
unsigned int	ClapTrap::getEnergyPoints( void ) const { return _EnergyPoints; }
unsigned int	ClapTrap::getAttackDamage( void ) const { return _AttackDamage; }
void			ClapTrap::setName( std::string name ) { _Name = name; }
void			ClapTrap::setHitPoints( unsigned int num ) { _HitPoints = num; }
void			ClapTrap::setEnergyPoints( unsigned int num ) { _EnergyPoints = num; }
void			ClapTrap::setAttackDamage( unsigned int num ) { _AttackDamage = num; }

// base function
void		ClapTrap::attack( std::string const & target )
{
	std::cout	<< "ClapTrap"
				<< " <" << _Name << ">"
				<< " attacks"
				<< " <" << target << ">"
				<< ", causing"
				<< " <" << _AttackDamage << ">"
				<< " points of damage!"
				<< std::endl;
}

void		ClapTrap::takeDamage( unsigned int amount )
{
	std::cout	<< "ClapTrap"
				<< " <" << _Name << ">"
				<< " takes"
				<< " <" << amount << ">"
				<< " damage."
				<< std::endl;
	if (_HitPoints < amount)
		_HitPoints = 0;
	else
		_HitPoints -= amount;
}

void		ClapTrap::beRepaired( unsigned int amount )
{
	std::cout	<< "ClapTrap"
				<< " <" << _Name << ">"
				<< " is repaired"
				<< " <" << amount << ">"
				<< " HP."
				<< std::endl;
	if (UINT_MAX - _HitPoints < amount)
		_HitPoints = UINT_MAX;
	else
		_HitPoints += amount;
}
