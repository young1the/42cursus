#include "Zombie.hpp"

int main()
{
	Zombie z(std::string("In main"));

	Zombie *zptr = newZombie(std::string("New Zombie"));
	zptr->Announce();
	delete zptr;
	randomChump(std::string("Random Chump"));
}
