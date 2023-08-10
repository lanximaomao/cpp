#include <iostream>
#include <vector>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n\n===== Animal =====\n\n";
	Animal* meta = new Animal();
	meta->makeSound();

	std::cout << "\n\n===== Dog or cat =====\n\n";
	Animal* d = new Dog();
	Animal* c = new Cat();
	d->makeSound();
	c->makeSound();

	std::cout << "\n\n===== wrong animal =====\n\n";
	WrongAnimal *wronganimal = new WrongAnimal();
	WrongAnimal *wrongcat = new WrongCat();
	wronganimal->makeSound();
	wrongcat->makeSound();

	std::cout << "\n\n===== clean up =====\n\n";
	delete meta;
	delete d;
	delete c;
	delete wronganimal;
	delete wrongcat;

	return (0);
}
