#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "escape_sequence.hpp"

int main(void)
{
	std::cout	<< GREEN;
	ClapTrap *clapscav = new ScavTrap("clapscav");
	std::cout	<< MAGENTA
				<< "[status]" << std::endl
				<< clapscav->getName() << std::endl
				<< clapscav->getHitPoints() << std::endl
				<< clapscav->getEnergyPoints() << std::endl
				<< clapscav->getAttackDamage() << std::endl;
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
