#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct00;
	ClapTrap ct01("ct01");
	ClapTrap ct02 = ct01;
	ClapTrap ct03(ct01);

	ct01.attack("mac");
	for (int i = 0;i < 12; ++i)
	{
		ct01.takeDamage(5);
		ct01.beRepaired(5);
	}
	ct01.attack("hello");
	ct02.attack("hi");
	ct03.attack("ohaio");
}