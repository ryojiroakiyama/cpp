#include "DiamondTrap.hpp"
#include "escape_sequence.hpp"

int main(void)
{
	std::cout	<< GREEN;
	DiamondTrap diamond("diamond");
	std::cout	<< MAGENTA;
	diamond.whoAmI();
	std::cout	<< "[other attributes] "
				<< diamond.getHitPoints()
				<< ", "
				<< diamond.getEnergyPoints()
				<< ", "
				<< diamond.getAttackDamage()
				<< std::endl;
	diamond.attack("Ben");
	std::cout	<< RESET;
}
