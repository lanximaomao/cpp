#include "Zombie.hpp"

int main()
{
	Zombie* z1 = newZombie("heap_zombie");
	z1->announce();
	randomChump("stack_zombie");
	delete z1;
	return (0);
}

