#include "ScavTrap.hpp"

int main()
{
	ClapTrap ct01("ct01");

	ct01.attack("mac");
	ScavTrap st00;
	ScavTrap st01("st01");
	st01.attack("mac");
	st01.beRepaired(10);
	st01.guardGate();

	ScavTrap *p_st = new ScavTrap("pointer");
	delete p_st;
}