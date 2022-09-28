#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {

private:

	std::string	type;

public:

	Weapon();
	Weapon(std::string type_in);
	~Weapon();
	const std::string &	getType() const;
	void				setType(std::string new_type);

};

#endif






