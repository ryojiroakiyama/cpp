#include "Zombie.hpp"
#include "escape_sequence.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout	<< RED
				<< _name
				<< " is dead"
				<< RESET
				<< std::endl;
}

void	Zombie::announce()
{
	std::cout	<< GREEN
				<< "<name> "
				<< _name 
				<< RESET
				<< std::endl;
}
