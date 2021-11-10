#include "HumanB.hpp"
#include "escape_sequence.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(0)
{
}

void	HumanB::attack()
{
	std::cout		<< CYAN
					<< _name
					<< " attacks with his ";
	if (_weapon)
		std::cout	<< _weapon->getType();
	else
		std::cout	<< "fist";
	std::cout		<< RESET
					<< std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}
