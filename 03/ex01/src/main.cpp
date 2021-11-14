#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "escape_sequence.hpp"

int main(void)
{
	std::cout	<< GREEN;
	ClapTrap *clapscav = new ScavTrap("clapscav");
	std::cout	<< MAGENTA
				<< "[attributes] "
				<< clapscav->getName()
				<< ", "
				<< clapscav->getHitPoints()
				<< ", "
				<< clapscav->getEnergyPoints()
				<< ", "
				<< clapscav->getAttackDamage()
				<< std::endl;
	std::cout	<< "[atack] ";
	clapscav->attack("Ben");

	std::cout	<< CYAN;
	delete clapscav;
	std::cout	<< GREEN;
	ScavTrap *scav = new ScavTrap();
	std::cout	<< MAGENTA;
	scav->guardGate();
	std::cout	<< CYAN;
	delete scav;
	std::cout	<< RESET;
}
