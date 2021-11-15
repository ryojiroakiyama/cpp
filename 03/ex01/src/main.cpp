#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "escape_sequence.hpp"

int main(void)
{
	std::cout	<< GREEN;
	ScavTrap	scav("scav");
	std::cout	<< MAGENTA
				<< "[attributes] "
				<< scav.getName()
				<< ", "
				<< scav.getHitPoints()
				<< ", "
				<< scav.getEnergyPoints()
				<< ", "
				<< scav.getAttackDamage()
				<< std::endl;
	std::cout	<< CYAN;
	scav.attack("Ben");
	scav.guardGate();
	std::cout	<< RESET;
}
