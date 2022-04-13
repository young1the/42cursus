#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap(), _guard_mode(false)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout <<"# ScavTrap's default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name_in)
: ClapTrap(name_in), _guard_mode(false)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout <<"# ScavTrap's string constructor called -> " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout <<"# ScavTrap's destructor called, [" << _name << "] destructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
: ClapTrap(other), _guard_mode(other._guard_mode)
{
	std::cout <<"# ScavTrap's copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator =(const ScavTrap& other)
{
	std::cout << "# ScavTrap's copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	this->_guard_mode = other._guard_mode;
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "[" << _name << "] is now in Gate keeper mode."<< std::endl;
	_guard_mode = true;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout <<"[" << _name << "] attacks scavly " << target;
		std::cout <<", causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_points--;
	}
	else
	{
		doNothing();
	}
}