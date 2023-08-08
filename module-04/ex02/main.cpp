#include <iostream>
#include <vector>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

// check for memory leaks

int main()
{
	std::cout << "\n\n===== Abstract Class =====\n\n";
	// this should not work
	// Animal a = new Animal();

	Dog* a = new Dog();
	std::cout << a->getName() << std::endl;
	a->makeSound();
	delete a;
	return (0);
}
