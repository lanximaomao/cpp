#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Garbage.hpp"

class Character: public ICharacter
{
	private:
		std::string		_name;
		static const	size_t _size = 4;
		AMateria*		_slots[_size];
		Garbage			_garbage;

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
