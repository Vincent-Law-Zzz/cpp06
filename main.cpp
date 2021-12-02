#include <typeinfo>
#include "Conversion.hpp"
#include <iostream>


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong argument's number!" << std::endl;
		return 0;
	}
	// char a[] = "abc";
	
	Conversion aboba = Conversion(argv[1]);
	std::cout << aboba.getArg() << std::endl;
	std::cout << argv[1] << std::endl;
	std::cout << "int :" << static_cast<float>(std::strtod("-10.912412123123123f", NULL)) << std::endl;
	std::cout << static_cast<float>(std::strtod(argv[1],NULL)) << std::endl;
	std::cout << static_cast<float>(1.0/3)  - static_cast<int>(1.0/3)<< std::endl;
	std::cout << ++argv[1] << std::endl;
	std::cout << argv[1] << std::endl;
	return 0;
}