#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data d;
	d.num = 125;
	Data *ptr =  Serializer::deserialize(Serializer::serialize(&d));
	std::cout << ptr->num <<std::endl;
	return (0);
}
