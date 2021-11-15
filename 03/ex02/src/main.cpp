#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "escape_sequence.hpp"

int main(void)
{
	std::cout	<< GREEN;
	FragTrap	frag("frag");
	std::cout	<< MAGENTA
				<< "[attributes] "
				<< frag.getName()
				<< ", "
				<< frag.getHitPoints()
				<< ", "
				<< frag.getEnergyPoints()
				<< ", "
				<< frag.getAttackDamage()
				<< std::endl;
	std::cout	<< CYAN;
	frag.highFivesGuys();
	std::cout	<< RESET;
}
