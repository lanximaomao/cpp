#include "Array.hpp"
#include <iostream>

#define MAX_VAL 12

int main()
{
	std::cout << "\n\n=====  basic functionality test =====\n\n";
	Array<int> test_random = Array<int>(MAX_VAL);
	int* mirror = new int(MAX_VAL);
	srand(time(NULL));
	for (size_t i = 0; i < MAX_VAL; i++)
	{
		int random_value = rand();
		test_random.getArray()[i] = random_value;
		mirror[i] = random_value;
	}
	for (size_t i = 0; i < MAX_VAL; i++)
		std::cout << test_random.getArray()[i] << " ";
	std::cout << std::endl;

	std::cout << "\n\n=====  deep copy test =====\n\n";
	Array<int> test_empty = Array<int>(0);
	std::cout << "old size = " << test_empty.size() << std::endl;
	test_empty = test_random;
	std::cout << "new size = " << test_empty.size() << std::endl;
	test_empty[2] = rand();
	for (size_t i = 0; i < MAX_VAL; i++)
	{
		if (test_empty.getArray()[i] != test_random.getArray()[i])
		{
			std::cout << "**** deep copy test successful.**** " << std::endl;
		}
	}

	std::cout << "\n\n=====  exception test =====\n\n";
	try
	{
		test_empty[1] = 12;
	}
	catch(const std::exception& ex)
	{
		std::cerr << "cannot access an empty array: " << ex.what() << std::endl;
	}
	try
	{
		test_random[12] = 12;
	}
	catch(const std::exception& ex)
	{
		std::cerr << "cannot access an index which is out of range: " << ex.what() << std::endl;
	}
	return (0);
}


//#include <iostream>
//#include "Array.hpp"

//#define MAX_VAL 750
//int main(int, char**)
//{
//    Array<int> numbers(MAX_VAL);
//    int* mirror = new int[MAX_VAL];
//    srand(time(NULL));
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        const int value = rand();
//        numbers[i] = value;
//        mirror[i] = value;
//    }
//    //SCOPE
//    {
//        Array<int> tmp = numbers;
//        Array<int> test(tmp);
//    }

//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        if (mirror[i] != numbers[i])
//        {
//            std::cerr << "didn't save the same value!!" << std::endl;
//            return 1;
//        }
//    }
//    try
//    {
//        numbers[-2] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//    try
//    {
//        numbers[MAX_VAL] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }

//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        numbers[i] = rand();
//    }
//    delete [] mirror;//
//    return 0;
//}
