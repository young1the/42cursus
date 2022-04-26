
#include "Converter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "! ARGUMENT ERROR !" << std::endl;
		return 1;
	}

	Converter c(argv[1]);
	std::cout << c << std::endl;
}

