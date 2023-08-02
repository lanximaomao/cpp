#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
	Zombie* z1 = newZombie("heap_zombie");
	z1->announce();
	delete z1;
	randomChump("stack_zombie");
	return (0);
}

