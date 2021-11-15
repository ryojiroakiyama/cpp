#include "ScavTrap.hpp"

// construcor, destructor
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor" << std::endl;
	setName("ScavTrap player1");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor" << std::endl;
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
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
