#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:

	std::string	_name;

public:

	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& other);
	DiamondTrap& operator = (const DiamondTrap& other);
	/* occf*/
	DiamondTrap(const std::string & name_in);
	void attack(std::string const & target);
	void whoAmI(void);

};

#endif
