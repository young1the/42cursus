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

DiamondTrap::DiamondTrap()
: ScavTrap(), FragTrap()
{
	std::cout << "# DiamondTrap's default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name_in)
: _name(name_in), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout <<"# DiamondTrap's string constructor called -> " << _name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout <<"# DiamondTrap's destructor called, [" << _name << "] destructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout <<"# DiamondTrap's copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap&	DiamondTrap::operator =(const DiamondTrap& other)
{
	std::cout <<"# DiamondTrap's copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}


#endif
