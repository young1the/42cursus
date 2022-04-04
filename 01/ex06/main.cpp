#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "# ERROR : Usage \"./harlFilter <message>\"" << std::endl;
		return (0);
	}
	Harl harl;
	harl.complain(std::string(argv[1]));
}
