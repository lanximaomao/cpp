#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP
# include <string>

// do we need constructors?
class WrongAnimal
{
	protected:
		std::string _type;
		std::string _name;

	public:
		WrongAnimal();
		WrongAnimal(const std::string name);
		WrongAnimal(const WrongAnimal &other);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal &other);

		//getters
		std::string getName() const;
		std::string getType() const;

		void makeSound() const;
};

# endif
