#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct01("ct01");

	ct01.attack("mac");
	for (int i = 0;i < 12; ++i)
	{
		ct01.takeDamage(5);
		ct01.beRepaired(5);
	}
}