#include <iostream>
#include "MateriaSource.hpp"

// init receipt
MateriaSource::MateriaSource()
: IMateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		_receipt[i] = "unknown";
}

MateriaSource::MateriaSource(const MateriaSource& other)
: IMateriaSource()
{
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 4; i++)
			_receipt[i] = other._receipt[i];
	}
	return (*this);
}

// free items
MateriaSource::~MateriaSource()
{
	//
}

// member function
//Copies the Materia passed as a parameter and store it in memory so it can be cloned later.
//Like the Character, the MateriaSource can know at most 4 Materias. They are not necessarily unique.
void MateriaSource::learnMateria(AMateria* other)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_receipt[i] == "unknown")
			_receipt[i] = other->getType();
	}
}
//Returns a new Materia. The latter is a copy of the Materia previously learned
//by the MateriaSource whose type equals the one passed as parameter. Returns 0 if the type is unknown.
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (type == _receipt[i])
		{
			if (type == "Cure")
				return (new Cure());
			else if (type == "Ice")
				return (new Ice());
			return (0);
		}
	}
}
