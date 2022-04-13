#include "Animal.hpp"

class Dog : public Animal {

private:

	/* data */

public:

	Dog(/* args */);
	~Dog();
	Dog(const Dog & other);
	Dog& operator = (const Dog & other);
	/* occf */

};

Dog::Dog(/* args */)
: Animal("Dog")
{
	std::cout << "# Dog's default constructor called" << std::endl;
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
	this->type = other.type;
}
