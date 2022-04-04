#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name)
{
	Zombie	*zombie_horde = new Zombie[n];

	for (int i = 0; i < n; i++)
	{
		std::string new_name;
		std::string number;

		number = std::to_string(i + 1);
		new_name = name + number;
		zombie_horde[i].ChangeName(new_name);
	}
	return (zombie_horde);
}
