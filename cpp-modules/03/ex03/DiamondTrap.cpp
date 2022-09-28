#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ScavTrap(), FragTrap()
{
	std::cout << "# DiamondTrap's default constructor called" << std::endl;
	ClapTrap::_name = "default_clap_name";
	_name = "default";
	_max_ep = 50;
	_energy_points = _max_ep;
}

DiamondTrap::DiamondTrap(const std::string& name_in)
: ScavTrap(), FragTrap()
{
	std::cout <<"# DiamondTrap's string constructor called -> " << _name << std::endl;
	ClapTrap::_name = name_in + "_clap_name";
	_name = name_in;
	_max_ep = 50;
	_energy_points = _max_ep;
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
	this->ClapTrap::_name = other.ClapTrap::_name;
	this->_max_hp = other._max_hp;
	this->_max_ep = other._max_ep;
	this->_attack_damage = other._attack_damage;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._hit_points;
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is [" << _name << "], Clapname is [" << ClapTrap::_name << "]" << std::endl;
}