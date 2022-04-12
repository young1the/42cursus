#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool	_guard_mode;
public:
	ScavTrap();
	ScavTrap(const std::string& name_in);
	~ScavTrap();
	void	attack(const std::string& target);
	void	guardGate();
};

ScavTrap::ScavTrap()
: ClapTrap(), _guard_mode(false)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout <<"# Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name_in)
: ClapTrap(name_in), _guard_mode(false)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
	std::cout <<"# ScavTrap [" << _name << "] constructed" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout <<"# ScavTrap [" << _name << "] destructed" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap [" << _name << "] is now in Gate keeper mode."<< std::endl;
	_guard_mode = true;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout <<"ScavTrap [" << _name << "] attacks " << target;
		std::cout <<", causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_points--;
	}
}