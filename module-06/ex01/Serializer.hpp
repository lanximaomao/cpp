#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <cstdint>
#include <string>

struct Data
{
	std::string str;
	int	num;
};


class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
