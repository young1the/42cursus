#include "WrongDog.hpp"

WrongDog::WrongDog()
: WrongAnimal()
{
	std::cout << "# WrongDog's default constructor called" << std::endl;
	type = "WrongDog";
}

WrongDog::~WrongDog()
{
	std::cout << "# WrongDog's destructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog & other)
: WrongAnimal(other)
{
	std::cout << "# WrongDog's copy constructor called" << std::endl;
}

WrongDog& WrongDog::operator = (const WrongDog & other)
{
	std::cout << "# WrongDog's copy assignment operator called" << std::endl;
	WrongAnimal::operator =(other);
	return *this;
}

/* occf end*/