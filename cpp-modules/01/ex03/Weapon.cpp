#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type_in)
{
	type = type_in;
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(std::string new_type)
{
	type = new_type;
}
