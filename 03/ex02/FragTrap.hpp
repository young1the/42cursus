#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

	/* data */

public:

	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap& operator = (const FragTrap& other);
	/* occf*/
	FragTrap(const std::string & name_in);
	void highFivesGuys(void);

};

FragTrap::FragTrap()
: ClapTrap(), 
{
}

FragTrap::~FragTrap()
{
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other), 
{

}
FragTrap& FragTrap::operator = (const FragTrap& other);
FragTrap::FragTrap(const std::string & name_in);
