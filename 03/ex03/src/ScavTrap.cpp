#include "ScavTrap.hpp"

std::string	ScavTrap::Scav_Name = "ScavTrap player1";
int			ScavTrap::Scav_HP = 100;
int			ScavTrap::Scav_EP = 50;
int			ScavTrap::Scav_AD = 20;

// construcor, destructor
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	setName(Scav_Name);
	setHitPoints(Scav_HP);
	setEnergyPoints(Scav_EP);
	setAttackDamage(Scav_AD);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor" << std::endl;
	setName(name);
	setHitPoints(Scav_HP);
	setEnergyPoints(Scav_EP);
	setAttackDamage(Scav_AD);
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor" << std::endl; }
ScavTrap::ScavTrap( const ScavTrap& original ) { *this = original; }

// oprator overload
ScavTrap&	ScavTrap::operator= ( const ScavTrap& right )
{
	setName(right.getName());
	setHitPoints(right.getHitPoints());
	setEnergyPoints(right.getEnergyPoints());
	setAttackDamage(right.getAttackDamage());
	return *this;
}

// base function
void	ScavTrap::attack( std::string const & target )
{
	std::cout	<< "ScavTrap"
				<< " <" << getName() << ">"
				<< " attacks"
				<< " <" << target << ">"
				<< ", causing"
				<< " <" << getAttackDamage() << ">"
				<< " points of damage!"
				<< std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout	<< "ScavTrap"
				<< " <" << getName() << ">"
				<< " enters in Gate keeper mode!"
				<< std::endl;
}
