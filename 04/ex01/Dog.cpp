#include "Dog.hpp"

Dog::Dog()
: Animal()
{
	std::cout << "# Dog's default constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "# Dog's destructor called" << std::endl;
}

Dog::Dog(const Dog & other)
: Animal(other)
{
	std::cout << "# Dog's copy constructor called" << std::endl;
}

Dog& Dog::operator = (const Dog & other)
{
	std::cout << "# Dog's copy assignment operator called" << std::endl;
	Animal::operator =(other);
	return *this;
}

/* occf end*/

void Dog::makeSound() const
{
	std::cout << "woof-woof!" << std::endl;
}
