#include "Zombie.hpp"

int main(void)
{
	Zombie	oZombie("original Zombie");
	Zombie	*nZombie;
	nZombie = oZombie.newZombie("new Zombie");
	delete nZombie;
	oZombie.randomChump("random Zombie");
	return (0);
}
