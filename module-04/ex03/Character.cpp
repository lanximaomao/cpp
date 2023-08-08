#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// init weapons?
Character::Character(const std::string name)
: ICharacter()
{
	_name = name;
	for (size_t i = 0; i < _size_inventory; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& other)
{
	*this = other;
}

// materials to be freed
// clear inventory
Character:: ~Character()
{
	for (size_t i = 0; i < _size_inventory; i++)
		delete _inventory[i];
}
// manage inventory

//AMateria* _inventory[_size_inventory];

Character& Character::operator=(const Character& other)
{
	size_t i;
	if (this != &other)
	{
		_name = other._name;
		for (i = 0; i < _size_inventory; i++)
			delete _inventory[i];
		for (i = 0; i < _size_inventory; i++)
		{
			if (other._inventory[i])
			{
				if (other._inventory[i]->getType() == "Ice")
					_inventory[i] = new Ice();
				else if (other._inventory[i]->getType() == "Cure")
					_inventory[i] = new Cure();
			}
		}
	}
	return (*this);
}

const std::string& Character::getName() const
{
	return (_name);
}

//
void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < _size_inventory; i++)
	{
		if (!_inventory[i])
			_inventory[i] = m;
	}
}
// not delete the object, but should avoid memory leak
void Character::unequip(int idx)
{
	if (_inventory[idx])
		_inventory[idx] = nullptr;
	for (size_t i= idx + 1; i < _size_inventory; i++)
	{
		if (_inventory[i])
		{
			_inventory[i - 1] = _inventory[i];
			_inventory[idx] = nullptr;
		}
	}
}

// use the Materia at the slot[idx], and pass the target parameter to the AMateria::use function.
void Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
	{
		_inventory[idx]->use(target);
	}
}
