#include "HumanA.hpp"

HumanA::HumanA(std::string name_in, Weapon &weapon_in)
: weapon(weapon_in), name(name_in)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack() const
{
	std::cout << name;
	std::cout << " attacks with their ";
	std::cout << weapon.getType();
	std::cout << std::endl;
}
