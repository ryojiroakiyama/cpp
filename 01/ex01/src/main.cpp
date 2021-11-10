#include "Zombie.hpp"

int main(void)
{
	int		N = 10;
	Zombie	*zombies = zombieHorde(N, "AKIYAMA");
	while (N--)
		zombies[N].announce();
	delete [] zombies;
	return (0);
}
