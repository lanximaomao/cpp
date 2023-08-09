#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

// During copy, the Materias of a Character
// must be deleted before the new ones are added to their inventory.

class Character: public ICharacter
{
	private:
		std::string _name;
		static const size_t _size = 4;
		AMateria* _inventory[_size];

	public:
		Character(const std::string name);
		Character(const Character& other);
		virtual ~Character();
		Character& operator=(const Character& other);

		virtual std::string const &getName() const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
