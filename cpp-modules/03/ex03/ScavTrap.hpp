#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:

	bool	_guard_mode;

public:

	ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator =(const ScavTrap& other);
	~ScavTrap();
	/* occf */
	ScavTrap(const std::string& name_in);

	void	attack(const std::string& target);
	void	guardGate();
	
};

#endif