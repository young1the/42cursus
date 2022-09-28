#include "HumanB.hpp"

HumanB::HumanB(std::string name_in)
{
	name = name_in;
}

HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	if ((*weapon).getType() == "")
	{
		std::cout << name << " has no weapon" << std::endl;
		return ;
	}
	std::cout << name;
	std::cout << " attacks with their ";
	std::cout << (*weapon).getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon_in)
{
	weapon = &weapon_in;
}
