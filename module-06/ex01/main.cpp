#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data d;
	d.str = "hello";
	d.num = 42;
	Data *ptr =  Serializer::deserialize(Serializer::serialize(&d));
	std::cout << ptr->str <<std::endl;
	std::cout << ptr->num <<std::endl;
	return (0);
}
