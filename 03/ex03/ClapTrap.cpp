#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: _name("defalut"), _max_hp(10), _max_ep(10), _attack_damage(0)
{
	std::cout << "# ClapTrap's default constructor called" << std::endl;
	_hit_points = _max_hp;
	_energy_points = _max_ep;
}

ClapTrap::ClapTrap(const std::string& name_in)
: _name("defalut"), _max_hp(10), _max_ep(10), _attack_damage(0)
{
	std::cout << "# ClapTrap's string constructor called -> " << _name << std::endl;
	_hit_points = _max_hp;
	_energy_points = _max_ep;
}

ClapTrap::~ClapTrap()
{
	std::cout <<"# ClapTrap's destructor called, [" << _name << "] destructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout <<"# ClapTrap's copy constructor called" << std::endl;
	*this = other;
}

ClapTrap&	ClapTrap::operator =(const ClapTrap& other)
{
	std::cout <<"# ClapTrap's copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	this->_max_ep = other._max_ep;
	this->_max_hp = other._max_hp;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout <<"[" << _name << "] attacks " << target;
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
		std::cout << "[" << _name << "] already dead..." << std::endl;
		return ;
	}
	std::cout << "[" << _name << "] takes damage " << amount;
	std::cout << "!" << std::endl;
	_hit_points -= amount;
	if (_hit_points <= 0)
	{
		std::cout << "[" << _name << "] DEAD!" << std::endl;
		_hit_points = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout << "[" << _name << "] repairs itself, ";
		std::cout << amount << " hit points back." << std::endl;
		_hit_points += amount;
		if (_hit_points > _max_hp)
			_hit_points = _max_hp;
		_energy_points--;
	}
	else
		doNothing();
}

void ClapTrap::doNothing(void)
{
	std::cout << "# [" << _name << "] can't do anything" << std::endl;
}

void	ClapTrap::showStatus(void)
{
	std::cout << "Name : " << _name << std::endl;
	std::cout << "Hit Points : " << _hit_points << std::endl;
	std::cout << "Energy Points : " << _energy_points << std::endl;
	std::cout << "Attack Damage : " << _attack_damage << std::endl;
}
