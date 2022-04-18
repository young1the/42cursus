#include "Animal.hpp"

Animal::Animal()
: type("default")
{
	std::cout << "# Animal's default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "# Animal's destructor called" << std::endl;
}

Animal::Animal(const Animal & other)
: type(other.type)
{
	std::cout << "# Animal's copy constructor called" << std::endl;
}

Animal& Animal::operator = (const Animal & other)
{
	std::cout << "# Animal's copy assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

/* occf end*/

const std::string &	Animal::getType() const
{
	return type;
}

void			Animal::makeSound() const
{
	std::cout << "?????" << std::endl;
}
