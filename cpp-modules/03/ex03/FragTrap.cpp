#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap()
{
	std::cout <<"# FragTrap's default constructor called" << std::endl;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout <<"# FragTrap's destructor called, [" << _name << "] destructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
: ClapTrap(other._name) 
{
	std::cout <<"# FragTrap's copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator = (const FragTrap& other)
{
	std::cout << "# FragTrap's copy assignment operator called" << std::endl;
	this->_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._hit_points;
	_attack_damage = other._attack_damage;
	return (*this);
}

FragTrap::FragTrap(const std::string & name_in)
: ClapTrap(name_in)
{
	std::cout <<"# FragTrap's string constructor called -> " << _name << std::endl;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout <<"[" << _name << "] requests a positive high fives" << std::endl;
}
