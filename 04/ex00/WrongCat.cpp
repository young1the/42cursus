#include "WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal()
{
	std::cout << "# WrongCat's default constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "# WrongCat's destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & other)
: WrongAnimal(other)
{
	std::cout << "# WrongCat's copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat & other)
{
	std::cout << "# WrongCat's copy assignment operator called" << std::endl;
	WrongAnimal::operator =(other);
	return *this;
}

/* occf end*/

void WrongCat::makeSound() const
{
	std::cout << "WrongCat : woem!" << std::endl;
}
