#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	std::cout << "\n\n=====  Learning new materia =====\n\n";

	IMateriaSource* src = new MateriaSource(); // change back to IMateriaSource
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n\n=====  Create new characters =====\n\n";

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	std::cout << "\n\n=====  Equip materials =====\n\n";
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n\n=====  Use materials =====\n\n";
	me->use(0, *bob);
	me->use(1, *bob);
	//me->use(2, *bob);
	//me->use(3, *bob);

	std::cout << "\n\n=====  unequip materias does not exist =====\n\n";
	me->unequip(0);
	me->unequip(1);

	std::cout << "\n\n=====  unequip exisit materias =====\n\n";
	me->unequip(2);
	me->unequip(3);

	std::cout << "\n\n=====  use something does not exisit =====\n\n";
	me->use(3, *bob);

	std::cout << "\n\n=====  Equip and unequip =====\n\n";
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	
	std::cout << "\n\n=====  clean up =====\n\n";
	delete bob;
	delete me;
	delete src;

	return 0;
}
