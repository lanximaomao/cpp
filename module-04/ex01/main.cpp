#include <iostream>
#include <vector>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "Color.hpp"

// check for memory leaks
// test that your copies are deep copies!

int main()
{
	std::cout << "\n\n===== Brain Class =====\n\n";

	Brain a;
	std::cout << a.getIdeas(10) << std::endl;
	std::string idea = "what for dinner?";
	a.setIdeas(10, idea);
	std::cout << COLOR_BLUE << a.getIdeas(10) << std::endl;
	std::cout << a.getIdeas(99) << std::endl << COLOR_RESET;

	Brain b = a;
	std::cout << COLOR_BLUE << b.getIdeas(10) << std::endl << COLOR_RESET;


	std::cout << "\n\n===== Allocate animals =====\n\n";
	const int animalCount = 4;
	Animal *animals[10];
	for (size_t i = 0; i < animalCount; i++)
	{
		if (i % 2)
			animals[i] = new Dog("cute");
		else
			animals[i] = new Cat("fat");
	}

	std::cout << "\n\n===== Dog's brain =====\n\n";
	Dog stackDog;
	std::string dogMsg = "so long, summer!";
	stackDog.getBrain()->setIdeas(2, dogMsg);
	std::cout << stackDog.getBrain()->getIdeas(2) << std::endl;

	std::cout << "\n\n===== Deep copy tests =====\n\n";
	Cat* heapCat = new Cat("sunny");
	std::string catMsg = "so long, my fish!";
	heapCat->getBrain()->setIdeas(60, catMsg);
	std::cout << heapCat->getBrain()->getIdeas(60) << std::endl;

	Cat stackCat = *heapCat;
	delete heapCat;
	stackCat.makeSound();

	std::cout << "\n\n===== Clean up =====\n\n";
	for (size_t i = 0; i < animalCount; i++)
	{
		delete animals[i];
	}
	return (0);
}
