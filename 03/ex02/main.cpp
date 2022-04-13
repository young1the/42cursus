#include "FragTrap.hpp"

int main()
{
	FragTrap ft01;
	std::cout << "-----<FragTrap's default con>-----" << '\n' << std::endl;
	FragTrap ft02("frag-ch");
	std::cout << "-----<FragTrap's string con>-----" << '\n' << std::endl;
	FragTrap ft03(ft02);
	std::cout << "-----<FragTrap's copy con>-----" << '\n' << std::endl;
	ft01 = ft03;
	std::cout << "-----<FragTrap's operator '='>-----" << '\n' << std::endl;

	ft02.showStatus();
	std::cout << std::endl;

	ft01.attack("his mac");
	ft01.beRepaired(10);
	std::cout << "-----<FragTrap's inherited function>-----" << '\n' << std::endl;
	ft01.highFivesGuys();
	std::cout << "-----<FragTrap's special capacity function>-----" << '\n' << std::endl;
}