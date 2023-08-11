#include <iostream>
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Color.hpp"

Character::Character(const std::string name)
: ICharacter()
, _name(name)
{
	std::cout << "Character constructor called\n";
	for (size_t i = 0; i < _size; i++)
		_slots[i] = 0;
}

Character:: ~Character()
{
	for (size_t i = 0; i < _size; i++)
		delete _slots[i];
	_garbage._deleteList();
	std::cout << "Character destructor called\n";
}

Character::Character(const Character& other)
: ICharacter()
{
	std::cout << "Character copy constructor called\n";
	*this = other;
}

/** be careful with _slots and _garbage */
Character& Character::operator=(const Character& other)
{
	size_t i;
	if (this != &other)
	{
		_name = other._name;
		for (i = 0; i < _size; i++)
		{
			if (_slots[i])
				delete _slots[i];
		}
		for (i = 0; i < _size; i++)
		{
			if (other._slots[i])
			{
				_slots[i] = other._slots[i]->clone();
			}
			else
				_slots[i] = NULL;
		}
		_garbage = other._garbage;
	}
	return (*this);
}

const std::string& Character::getName() const
{
	return (_name);
}

/** if not able to equip, drop on the floor = add to garbage collector */
void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (size_t i = 0; i < _size; i++)
	{
		if (!_slots[i])
		{
			_slots[i] = m;
			std::cout << m->getType() << " equipped successfully\n";
			return;
		}
	}
	std::cout << COLOR_RED << "full inventory, cann't eqip\n" << COLOR_RESET;
	_garbage.pushBack(*m);
}

/** unquiped items goes to garbage collector */
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "invalid idx for unequip\n";
		return;
	}
	if (!_slots[idx])
	{
		std::cout << "no material at this slot\n";
		return;
	}
	_garbage.pushBack(*_slots[idx]);
	std::cout << "unequiped " << _slots[idx]->getType() << " successfully!\n";
	_slots[idx] = 0;
}

/** use the Materia at the slot[idx], delete after use */
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return;
	if (!_slots[idx])
	{
		std::cout << "empty slots.\n";
		return;
	}
	_slots[idx]->use(target);
	delete _slots[idx];
	_slots[idx] = NULL;
}
