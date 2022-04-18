#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: type("default")
{
	std::cout << "# WrongAnimal's default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "# WrongAnimal's destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & other)
: type(other.type)
{
	std::cout << "# WrongAnimal's copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal & other)
{
	std::cout << "# WrongAnimal's copy assignment operator called" << std::endl;
	this->type = other.type;
	return *this;
}

/* occf end*/

const std::string &	WrongAnimal::getType() const
{
	return type;
}

void			WrongAnimal::makeSound() const
{
	std::cout << "?????" << std::endl;
}
