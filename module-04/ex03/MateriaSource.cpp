#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
: IMateriaSource()
{
	std::cout << "MateriaSource constructor called\n";
	for (size_t i = 0; i < 4; i++)
	{
		_receipt[i] = 0; // init to null
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
: IMateriaSource()
{
	std::cout << "MateriaSource copy constructor called\n";
	*this = other;
}

// free first?
MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 4; i++)
		{
			delete _receipt[i];
			_receipt[i] = other._receipt[i];
		}
	}
	return (*this);
}

// free items
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called\n";
	for (size_t i = 0; i < 4; i++)
	{
		delete _receipt[i];
	}
}

// member function
//Copies the Materia passed as a parameter and store it in memory so it can be cloned later.
//Like the Character, the MateriaSource can know at most 4 Materias. They are not necessarily unique.
void MateriaSource::learnMateria(AMateria* other)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!_receipt[i]) // if it is null
		{
			_receipt[i] = other;
			return ;
		}
	}
}
//Returns a new Materia. The latter is a copy of the Materia previously learned
//by the MateriaSource whose type equals the one passed as parameter. Returns 0 if the type is unknown.
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_receipt[i] && _receipt[i]->getType() == type)
		{
			if (type == "ice")
			{
				//std::cout << "creating ice\n";
				return (new Ice());
			}
			else if (type == "cure")
			{
				//std::cout << "creating cure\n";
				return (new Cure());
			}
			return (0);
		}
		//std::cout << _receipt[i] << std::endl;
	}
	return (0);
}

AMateria* MateriaSource::getReceipt(int i) const
{
	if (i >= 0 && i <= 3)
		return(_receipt[i]);
	std::cout << "index should be between 0 - 3\n";
	return (0);
}

