#include <iostream>
#include <sstream>

// how each different data type is stored in memory? char, int, floate, double

int main() {
    int x = 42;

    // Reinterpret the integer as a pointer
    int* ptr = &x;
    char* charPtr = reinterpret_cast<char*>(ptr);

	std::cout << static_cast<int>(*charPtr) << std::endl;
    // Output the individual bytes of the integer using the char pointer
    for (size_t i = 0; i < sizeof(int); ++i) {
        std::cout << "Byte " << i << ": " << static_cast<int>(charPtr[i]) << std::endl;
    }

    return 0;
}


void converter(std::string input)
{
	std::stringstream ss(input);

	int asInt = 0;
	char asChar = 'a';
	double asDouble = 0.0;
	float asFloat = 0.0;

	ss >> asChar;
	ss.clear();
	ss.seekg(0);

	ss >> asInt;
	ss.clear();
	ss.seekg(0);

	ss >> asFloat;
	ss.clear();
	ss.seekg(0);

	ss >> asDouble;
	ss.clear();
	ss.seekg(0);

	std::cout << "char: " << asChar <<std::endl;
	std::cout << "int: " << asInt <<std::endl;
	std::cout << "float: " << asFloat <<std::endl;
	std::cout << "double: " << asDouble <<std::endl;

}
