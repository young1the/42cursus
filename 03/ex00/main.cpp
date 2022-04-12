#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct00;
	ClapTrap ct01("ct01");
	ClapTrap ct02 = ct01;
	ClapTrap ct03(ct01);

	ct01.attack("mac");
	std::cout << "# Stress test ct01" << std::endl;
	for (int i = 0;i < 12; ++i)
	{
		ct01.takeDamage(5);
		ct01.beRepaired(5);
	}
}