#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


// copy and assignment are deep copy
Character::Character(const std::string name)
: ICharacter()
, _name(name)
{
	std::cout << "Character constructor called\n";
	for (size_t i = 0; i < _size; i++)
		_inventory[i] = 0;
}

Character::Character(const Character& other)
: ICharacter()
{
	std::cout << "Character copy constructor called\n";
	*this = other;
}

// clear inventory
Character:: ~Character()
{
	for (size_t i = 0; i < _size; i++)
		delete _inventory[i]; // no virtual destructor
	std::cout << "Character destructor called\n";
}

// free first
Character& Character::operator=(const Character& other)
{
	size_t i;
	if (this != &other)
	{
		_name = other._name;
		for (i = 0; i < _size; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
		}
		for (i = 0; i < _size; i++)
		{
			if (other._inventory[i])
			{
				if (other._inventory[i]->getType() == "ice")
					_inventory[i] = new Ice();
				else if (other._inventory[i]->getType() == "cure")
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


void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < _size; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "equip weapon\n";
			return;
		}
	}
}

// not delete the object, but should avoid memory leak
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	else
	{
		// save the address for free
		std::cout << "unequip weapon\n";
		_inventory[idx] = 0;
		for (size_t i = idx + 1; i < _size; i++)
		{
			if (_inventory[i])
			{
				_inventory[i - 1] = _inventory[i];
				_inventory[idx] = 0;
			}
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
