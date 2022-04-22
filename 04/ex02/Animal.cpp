#include "Animal.hpp"

Animal::Animal()
: type("Animal")
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

Animal::Animal(const std::string & type_in)
: type(type_in)
{
	std::cout << "# Animal's default constructor called" << std::endl;
}

/* occf end*/

const std::string &	Animal::getType() const
{
	return type;
}

// void			Animal::makeSound() const
// {
// 	std::cout << "!Unknown Sound!" << std::endl;
// }
