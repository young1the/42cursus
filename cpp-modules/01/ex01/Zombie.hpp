#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

private:

	std::string	name;

public:

	Zombie();
	Zombie(std::string name_input);
	~Zombie();

	void	Announce(void) const;
	void	ChangeName(std::string new_name);

};

Zombie*	zombieHorde(int n, std::string name);

#endif
