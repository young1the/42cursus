#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:

public:

	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap& operator = (const FragTrap& other);
	/* occf*/
	FragTrap(const std::string & name_in);
	void highFivesGuys(void);

};

#endif