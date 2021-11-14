#include "FragTrap.hpp"

// construcor, destructor
FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
	setName("FragTrap player1");
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor" << std::endl;
	setName(name);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor" << std::endl; }
FragTrap::FragTrap( const FragTrap& original ) { *this = original; }

// oprator overload
FragTrap&	FragTrap::operator= ( const FragTrap& right )
{
	setName(right.getName());
	setHitPoints(right.getHitPoints());
	setEnergyPoints(right.getEnergyPoints());
	setAttackDamage(right.getAttackDamage());
	return *this;
}

// base function
void	FragTrap::highFivesGuys()
{
	std::cout << "Hey high touch!" << std::endl;
}
