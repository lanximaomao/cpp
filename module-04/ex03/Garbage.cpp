#include <iostream>
#include "Garbage.hpp"
#include "AMateria.hpp"


Garbage::Garbage(): _materia_list(NULL)
{
	std::cout << "Garbage collector starts to work\n";
}

Garbage::Garbage(Garbage& other)
{
	std::cout << "Garbage copy constructor\n";

	AMateria *tmp;
	tmp = other._materia_list;
	while (tmp)
	{
		pushBack(*tmp);
		tmp = tmp->_next;
	}
}

Garbage* Garbage::operator=(Garbage *other)
{
	std::cout << "Garbage copy assignment\n";
	this->_deleteList();

	AMateria *tmp = other->_materia_list;
	while (tmp)
	{
		this->pushBack(*tmp);
		tmp = tmp->_next;
	}
	return(this);
}

void Garbage:: pushBack(AMateria& material)
{
	AMateria *tmp;

	if (!_materia_list)
		_materia_list = &material;
	else
	{
		tmp = _materia_list;
		while (tmp->_next)
		{
			tmp = tmp->_next;
		}
		tmp->_next = &material;
	}
}

void Garbage::_deleteList()
{
	AMateria *tmp;

	while (_materia_list)
	{
		tmp = _materia_list->_next;
		delete _materia_list;
		_materia_list = tmp;
	}
}

Garbage::~Garbage()
{
	std::cout << "Time to destory everything\n";
	_deleteList();
}
