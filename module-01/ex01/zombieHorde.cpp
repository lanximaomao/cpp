#include "Zombie.hpp"

Zombie * zombieHorde(int N, std::string name)
{
	Zombie* z_army = new Zombie[N];
	for (int i = 0; i < N; i++)
		z_army[i].setName(name);
	return (z_army);
}
