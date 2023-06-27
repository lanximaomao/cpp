#include "Harl.hpp"

// std::mem_fun_ref
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Please insert filter level " << std::endl;
		return(1);
	}
	Harl h1;
	h1.complain_filter(argv[1]);
	return (0);
}



