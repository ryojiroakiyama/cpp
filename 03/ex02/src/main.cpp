#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "escape_sequence.hpp"

int main(void)
{
	std::cout	<< GREEN;
	ClapTrap *clapfrag = new FragTrap("clapfrag");
	std::cout	<< MAGENTA
				<< "[attributes] "
				<< clapfrag->getName()
				<< ", "
				<< clapfrag->getHitPoints()
				<< ", "
				<< clapfrag->getEnergyPoints()
				<< ", "
				<< clapfrag->getAttackDamage()
				<< std::endl;

	std::cout	<< CYAN;
	delete clapfrag;
	std::cout	<< GREEN;
	FragTrap *Frag = new FragTrap();
	std::cout	<< MAGENTA;
	Frag->highFivesGuys();
	std::cout	<< CYAN;
	delete Frag;
	std::cout	<< RESET;
}
