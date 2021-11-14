#include "ClapTrap.hpp"
#include "escape_sequence.hpp"

int main(void)
{
	ClapTrap p1_orginal;
	ClapTrap Ben("Ben");
	ClapTrap p1 = p1_orginal;

	std::cout << MAGENTA << "player1 HP:" << p1.getHitPoints() << RESET << std::endl;
	std::cout << MAGENTA << "Ben HP:" << Ben.getHitPoints() << RESET << std::endl;
	p1.attack("Ben");
	Ben.takeDamage(5);
	std::cout << MAGENTA << "player1 HP:" << p1.getHitPoints() << RESET << std::endl;
	std::cout << MAGENTA << "Ben HP:" << Ben.getHitPoints() << RESET << std::endl;
	Ben.attack("player1");
	p1.takeDamage(100);
	std::cout << MAGENTA << "player1 HP:" << p1.getHitPoints() << RESET << std::endl;
	std::cout << MAGENTA << "Ben HP:" << Ben.getHitPoints() << RESET << std::endl;
	p1.beRepaired(1000);
	p1.beRepaired(UINT_MAX);
	std::cout << MAGENTA << "player1 HP:" << p1.getHitPoints() << RESET << std::endl;
	std::cout << MAGENTA << "Ben HP:" << Ben.getHitPoints() << RESET << std::endl;
	Ben.beRepaired(5);
	std::cout << MAGENTA << "player1 HP:" << p1.getHitPoints() << RESET << std::endl;
	std::cout << MAGENTA << "Ben HP:" << Ben.getHitPoints() << RESET << std::endl;
}
