#include "FragTrap.hpp"

std::string	FragTrap::Frag_Name = "FragTrap player1";
int			FragTrap::Frag_HP = 100;
int			FragTrap::Frag_EP = 100;
int			FragTrap::Frag_AD = 30;

// construcor, destructor
FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor" << std::endl;
	setName(Frag_Name);
	setHitPoints(Frag_HP);
	setEnergyPoints(Frag_EP);
	setAttackDamage(Frag_AD);
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor" << std::endl;
	setName(name);
	setHitPoints(Frag_HP);
	setEnergyPoints(Frag_EP);
	setAttackDamage(Frag_AD);
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
