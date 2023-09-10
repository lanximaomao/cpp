#include <iostream>

void printCharBinary(char c)
{
	const int size = sizeof(c) * 8;
	for (int i = size - 1; i >= 0; i--)
	{
		char bit = c >> i & 1;
		std::cout << static_cast<int>(bit);
		//std::cout << bit;
		if (i % 8 == 0)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void printIntBinary(int num)
{
	const int size = sizeof(num) * 8;
	for (int i = size - 1; i >= 0; i--)
	{
		char bit = num >> i & 1;
		std::cout << static_cast<int>(bit);
		if (i % 8 == 0)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void printFloatBinary(float num)
{
	const int size = sizeof(num);
	unsigned char* bits = reinterpret_cast<unsigned char*>(&num);
	for (int i = size - 1; i >= 0 ; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			std::cout << (bits[i] >> j & 1);
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}
