#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {

protected:

	std::string	_name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;

	void		doNothing();

public:

	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator =(const ClapTrap& other);
	/* occf */
	ClapTrap(const std::string& name_in);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	void		showStatus(void);

};

#endif