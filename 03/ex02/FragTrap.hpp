#include "ClapTrap.hpp"

class FragTrap
{
private:
	/* data */
public:
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap&	operator =(const FragTrap& other);
};

FragTrap::FragTrap(/* args */)
{
}

FragTrap::~FragTrap()
{
}

FragTrap::FragTrap(const FragTrap& other)
{

}

FragTrap&	FragTrap::operator =(const FragTrap& other)
{
	std::cout << "Copy Assignment constructor called" << std::endl;
	*this = other;
}