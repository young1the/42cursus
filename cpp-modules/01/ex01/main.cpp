#include "Zombie.hpp"

int main()
{
	Zombie *zptr = zombieHorde(3, std::string("Random Zombie"));
	for (int i = 0; i < 3; i++)
		zptr[i].Announce();
	delete[] zptr;
}
