#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

//int	main(void)
//{
//	//std::cout << "\n\n=== Concrete Materia Class ===\n\n";
//	//AMateria*	i = new Ice();
//	//std::cout << "Type of material is: " << i->getType() << std::endl;
//	//AMateria*	c = new Cure();
//	//std::cout << "Type of material is: " << c->getType() << std::endl;

//	//std::cout << "\n\n=== Concrete Character Class ===\n\n";
//	//ICharacter*	me = new Character("me");
//	//ICharacter*	bob = new Character("bob");

//	std::cout << "\n\n=== Concrete Material source Class ===\n\n";
//	MateriaSource* src = new MateriaSource();
//	src->createMateria("Ice");
//	return (0);
//}


int main()
{
	std::cout << "\n\n=====  Learning new materia =====\n\n";

	IMateriaSource* src = new MateriaSource(); // change back to IMateriaSource
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << src->getReceipt(0)->getType() << std::endl;
	std::cout << src->getReceipt(1)->getType() << std::endl;
	std::cout << src->getReceipt(2)->getType() << std::endl;
	std::cout << src->getReceipt(3)->getType() << std::endl;

	std::cout << "\n\n=====  Create and equip =====\n\n";

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	//std::cout << "\n\n=====  Unequip materia =====\n\n";
	//me->unequip(0);
	//me->unequip(1);
	//me->unequip(2);
	//me->unequip(3);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n\n=====  clean up =====\n\n";
	delete bob;
	delete me;
	delete src;

	return 0;
}
