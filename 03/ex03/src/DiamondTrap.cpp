#include "DiamondTrap.hpp"

// construcor, destructor
DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor" << std::endl;
	_Name = "DiamondTrap player1";
	setName(_Name + std::string( "_clap_name"));
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap constructor" << std::endl;
	_Name = name;
	setName(_Name + "_clap_name");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(30);
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor" << std::endl; }
DiamondTrap::DiamondTrap( const DiamondTrap& original ) { *this = original; }

// oprator overload
DiamondTrap&	DiamondTrap::operator= ( const DiamondTrap& right )
{
	_Name = right._Name;
	setName(right.getName());
	setHitPoints(right.getHitPoints());
	setEnergyPoints(right.getEnergyPoints());
	setAttackDamage(right.getAttackDamage());
	return *this;
}

// base function
void			DiamondTrap::whoAmI()
{
	std::cout << "[name] " << _Name << std::endl;
	std::cout << "[clapTrap name] " << getName() << std::endl;
}
