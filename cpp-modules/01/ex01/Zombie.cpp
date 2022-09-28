#include "Zombie.hpp"

Zombie::Zombie()
{
	name = std::string("Zombie");
}

Zombie::Zombie(std::string name_input)
{
	name = name_input;
}

Zombie::~Zombie()
{
	std::cout << "# ";
	std::cout << name;
	std::cout << " has been destructed";
	std::cout << std::endl;
}

void	Zombie::Announce(void) const
{
	std::cout << name;
	std::cout << ": BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

void	Zombie::ChangeName(std::string new_name)
{
	name = new_name;
}
