#pragma once
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {

private:

	Weapon		*weapon;
	std::string	name;

public:

	HumanB(std::string name_in);
	~HumanB();
	void	attack() const;
	void	setWeapon(Weapon &weapon_in);

};

#endif
