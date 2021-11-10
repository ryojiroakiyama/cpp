#include "HumanA.hpp"
#include "escape_sequence.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

void	HumanA::attack()
{
	std::cout	<< MAGENTA
				<< _name
				<< " attacks with his "
				<< _weapon.getType()
				<< RESET
				<< std::endl;
}
