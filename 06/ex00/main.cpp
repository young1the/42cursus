#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "! ARGUMENT ERROR !" << std::endl;
		return 1;
	}

	char *endptr;
	double value = std::strtod(argv[1], &endptr);
	std::cout << value << std::endl;
	if(std::isnan(value) || std::isinf(value))
		std::cout << "isnan" << std::endl;
	std::cout << endptr << std::endl;
	std::string str = endptr;
	std::cout << str.size() << std::endl;
}

