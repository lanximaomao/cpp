#include <iostream>
#include <vector>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "Color.hpp"

int main()
{
	std::cout << "\n\n===== Brain Class =====\n\n";

	Brain a;
	std::cout << a.getIdeas(10) << std::endl;
	std::string idea = "what for dinner?";
	a.setIdeas(10, idea);
	std::cout << COLOR_BLUE << "idea 10: " << a.getIdeas(10) << std::endl;
	std::cout << "idea 99:" << a.getIdeas(99) << std::endl << COLOR_RESET;

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
	std::cout << COLOR_RED << stackDog.getBrain()->getIdeas(2) << std::endl << COLOR_RESET;

	std::cout << "\n\n===== Deep copy test 1 =====\n\n";
	Cat* heapCat = new Cat("sunny");
	Cat stackCat = *heapCat;
	delete heapCat;
	std::cout << COLOR_RED << stackCat.getBrain()->getIdeas(2) << std::endl << COLOR_RESET;

	std::cout << "\n\n===== Deep copy test 2 =====\n\n";
	Dog basic;
	{
		Dog tmp = basic;
	}
	std::cout << COLOR_RED << basic.getBrain()->getIdeas(0) << std::endl << COLOR_RESET;

	std::cout << "\n\n===== Clean up =====\n\n";
	for (size_t i = 0; i < animalCount; i++)
	{
		delete animals[i];
	}
	return (0);
}
