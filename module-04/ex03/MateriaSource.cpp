#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
: IMateriaSource()
{
	std::cout << "MateriaSource constructor called\n";
	for (size_t i = 0; i < 4; i++)
	{
		_materials[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
: IMateriaSource()
{
	std::cout << "MateriaSource copy constructor called\n";
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		this->IMateriaSource::operator=(other);
		for (size_t i = 0; i < 4; i++)
		{
			_materials[i] = createMateria(other._materials[i]->getType());
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called\n";
	for (size_t i = 0; i < 4; i++)
	{
		delete _materials[i];
	}
}

void MateriaSource::learnMateria(AMateria* other)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!_materials[i])
		{
			_materials[i] = other;
			return ;
		}
	}
	delete other;
	std::cout << "no more space for learning new materials\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_materials[i] && _materials[i]->getType() == type)
		{
			return(_materials[i]->clone());
		}
	}
	return (0);
}
