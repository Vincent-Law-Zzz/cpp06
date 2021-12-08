#include <typeinfo>
#include "Conversion.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: Wrong argument's number!" << std::endl;
		return 0;
	}

	Conversion aboba(argv[1]);
	std::cout << aboba << std::endl;
	return 0;
}