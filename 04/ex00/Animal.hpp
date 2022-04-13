#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {

private:
	/* data */

protected:
	std::string	type;
public:

	Animal(/* args */);
	~Animal();
	Animal(const Animal & other);
	Animal& operator = (const Animal & other);
	/* occf */
	Animal(const std::string &name_in);

};

Animal::Animal(/* args */)
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
}

Animal::Animal(const std::string &name_in)
: type(name_in)
{
	std::cout << "# Animal's string constructor called" << std::endl;
}

#endif