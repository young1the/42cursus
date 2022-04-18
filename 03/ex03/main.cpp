#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap dt01;
	std::cout << "-----<DiamondTrap's default con>-----" << '\n' << std::endl;
	DiamondTrap dt02("diamond-ch");
	std::cout << "-----<DiamondTrap's string con>-----" << '\n' << std::endl;
	DiamondTrap dt03(dt02);
	std::cout << "-----<DiamondTrap's copy con>-----" << '\n' << std::endl;
	dt01 = dt03;
	std::cout << "-----<DiamondTrap's operator '='>-----" << '\n' << std::endl;

	{
		FragTrap ft01("ft");
		ScavTrap st01("sc");
		ft01.showStatus();
		st01.showStatus();
		dt02.showStatus();
		std::cout << std::endl;
	}

	dt01.attack("his mac");
	dt01.beRepaired(10);
	dt01.highFivesGuys();
	dt01.guardGate();
	std::cout << "-----<DiamondTrap's inherited function>-----" << '\n' << std::endl;

	dt01.whoAmI();
	std::cout << "-----<DiamondTrap's special capacity function>-----" << '\n' << std::endl;
}