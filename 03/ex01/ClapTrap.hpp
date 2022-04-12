#include <iostream>
#include <string>

class ClapTrap {

protected:

	std::string	_name;
	int			_hit_points;
	int			_energy_points;
	int			_attack_damage;

	void		doNothing();

public:

	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator =(const ClapTrap& other);
	/* occf */
	ClapTrap(const std::string& name_in);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

};

ClapTrap::ClapTrap()
: _name("defalut"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "# ClapTrap's default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name_in)
: _name(name_in), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout <<"# ClapTrap [" << _name << "] constructed" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout <<"# ClapTrap [" << _name << "] destructed" << std::endl;
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
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout <<"ClapTrap [" << _name << "] attacks " << target;
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
		std::cout << "ClapTrap [" << _name << "] already dead..." << std::endl;
		return ;
	}
	std::cout << "ClapTrap [" << _name << "] takes damage " << amount;
	std::cout << "!" << std::endl;
	_hit_points -= amount;
	if (_hit_points <= 0)
	{
		std::cout << "ClapTrap [" << _name << "] DEAD!" << std::endl;
		_hit_points = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points > 0 && _energy_points > 0)
	{
		std::cout << "ClapTrap [" << _name << "] repairs itself, ";
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
	std::cout << "# [" << _name << "] can't do anything" << std::endl;
}
