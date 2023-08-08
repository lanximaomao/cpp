#include <iostream>
#include <vector>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// check for memory leaks

int main()
{
	std::cout << "\n\n===== DOG OR CAT =====\n\n";
	const Animal *meta = new Animal();
	meta->makeSound();

	// on stack
	Dog a = Dog();
	a.makeSound();

	Dog b = Dog("b");
	b.makeSound();

	Dog c = Dog(b);
	c.makeSound();

	Dog d = a;
	d.makeSound();

	// create a dog object on heap
	const Animal *doggy = new Dog();
	std::cout << doggy->getType() << " " << std::endl;
	doggy->makeSound();

	// create a cat object on heap
	const Animal *catty = new Cat();
	std::cout << catty->getType() << " " << std::endl;
	catty->makeSound();

	//Wrong animal and wrong cat
	WrongAnimal wrong_animal = WrongAnimal();
	WrongAnimal wrong_cat = WrongCat();
	wrong_animal.makeSound();
	wrong_cat.makeSound();

	// more cat and dog
	Animal *mooncake = new Cat("mooncake");
	Animal *sini = new Dog("sini");

	// in vector
	std::vector<Animal *> army;
	army.push_back(mooncake);
	army.push_back(sini);

	for (int i = 0; i < 2; i++)
		army[i]->makeSound();

	// in array
	Animal* dog_army = new Dog[5];
	Animal* cat_army = new Cat[5];

	for (int i = 0; i < 5; i++)
	{
		dog_army[i].makeSound();
		cat_army[i].makeSound();
	}

	// clean up
	delete doggy;
	delete catty;
	delete mooncake;
	delete sini;

	// why illegal instructions?
	delete [] dog_army;
	delete [] cat_army;

	return (0);
}
