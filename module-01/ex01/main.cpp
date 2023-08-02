#include "Zombie.hpp"

/*
** when I accidently delete the army in the zombieHorde
** why my zombie army still annouce?
*/

void		randomChump( std::string name );
Zombie*		newZombie( std::string name );
Zombie*		zombieHorde(int N, std::string name);

int main()
{
	int army_size;

	army_size = 5;
	Zombie* army = zombieHorde(army_size, "Cutest");
	for(int i = 0; i < army_size; i++)
		army[i].announce();
	delete [] army;
	return (0);
}

