#include "ScavTrap.hpp"

int main()
{
	ScavTrap st01;
	std::cout << "-----<ScavTrap's default con>-----" << '\n' << std::endl;
	ScavTrap st02("scav-ch");
	std::cout << "-----<ScavTrap's string con>-----" << '\n' << std::endl;
	ScavTrap st03(st02);
	std::cout << "-----<ScavTrap's copy con>-----" << '\n' << std::endl;
	st01 = st03;
	std::cout << "-----<ScavTrap's operator '='>-----" << '\n' << std::endl;

	st02.showStatus();
	std::cout << std::endl;

	st01.beRepaired(10);
	std::cout << "-----<ScavTrap's inherited function>-----" << '\n' << std::endl;

	ClapTrap ct01("clap-ch");
	ct01.attack("his mac");
	st01.attack("his mac");
	std::cout << "-----<ScavTrap's override function>-----" << '\n' << std::endl;

	st01.guardGate();
	std::cout << "-----<ScavTrap's special capacity function>-----" << '\n' << std::endl;
}