#include <iostream>
#include <string>

class ClapTrap {

private:

	std::string	_name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;

public:

	ClapTrap(const std::string& name_in);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void doNothing(void);
};

ClapTrap::ClapTrap(const std::string& name_in)
: _name(name_in), _hit_points(10), _energy_points(10), _attack_damage(0)
{
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout <<"ClapTrap " << _name << " attacks " << target;
		std::cout <<", causing " << _attack_damage << " points of damage!" << std::endl;
		_energy_points--;
	}
	else
		doNothing();
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points == 0)
	{
		std::cout << "ClapTrap " << _name << " already dead..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes damage " << amount;
	std::cout << "!" << std::endl;
	_hit_points -= amount;
	if (_hit_points <= 0)
	{
		std::cout << "ClapTrap " << _name << " DEAD!" << std::endl;
		_hit_points = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout << "ClapTrap " << _name << " repairs itself,";
		std::cout << amount << " hit points back." << std::endl;
		_hit_points += amount;
		if (_hit_points > 10)
			_hit_points = 10;
		_energy_points--;
	}
	else
		doNothing();
}

void ClapTrap::doNothing(void)
{
	std::cout << "ClapTrap " << _name << " can't do anything" << std::endl;
}

