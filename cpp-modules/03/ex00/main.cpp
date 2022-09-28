#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct01;
	std::cout << "-----<ClapTrap's default con>-----" << '\n' << std::endl;
	ClapTrap ct02("clap-ch");
	std::cout << "-----<ClapTrap's string con>-----" << '\n' << std::endl;
	ClapTrap ct03(ct02);
	std::cout << "-----<ClapTrap's copy con>-----" << '\n' << std::endl;
	ct01 = ct03;
	std::cout << "-----<ClapTrap's operator '='>-----" << '\n' << std::endl;

	ct01.showStatus();
	std::cout << std::endl;

	ct01.attack("his mac");
	std::cout << "# STRESS TEST" << std::endl;
	for (int i = 0;i < 12; ++i)
	{
		ct01.takeDamage(5);
		ct01.beRepaired(5);
	}
}